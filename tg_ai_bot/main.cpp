#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <tgbot/tgbot.h>

using namespace std;
using namespace TgBot;

// Функция для отправки HTTP POST запроса в локальную Ollama через системный curl
string askOllama(const string& userInput) {
    // Добавим инструкцию, чтобы модель была краткой
    string safeInput = "Отвечай кратко и по существу. Вопрос: ";
    for (char c : userInput) {
        if (c == '"') safeInput += "\\\"";
        else if (c == '\\') safeInput += "\\\\";
        else safeInput += c;
    }

    // Формируем bash-команду для curl.
    // Важно: здесь нет переносов строк внутри кавычек, чтобы избежать ошибок сборки
    string cmd = "curl -s -X POST http://localhost:11434/api/generate -d '{\"model\": \"tinyllama\", \"prompt\": \"" + safeInput + "\", \"stream\": false}'";

    // Выполняем команду и читаем ответ
    char buffer[128];
    string result = "";
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    
    if (!pipe) {
        return "❌ Ошибка: Не удалось связаться с подсистемой ИИ.";
    }
    
    while (fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
        result += buffer;
    }

    // Парсинг ответа (ищем поле "response")
    string searchKey = "\"response\":\"";
    size_t startPos = result.find(searchKey);
    if (startPos == string::npos) {
        return "🤖 Хм, не удалось разобрать ответ от модели.";
    }
    startPos += searchKey.length();
    
    size_t endPos = result.find("\"", startPos);
    if (endPos == string::npos) return "🤖 Ошибка при разборе ответа.";

    string aiText = result.substr(startPos, endPos - startPos);

    // Базовая очистка текста от экранированных символов
    string cleanText = "";
    for (size_t i = 0; i < aiText.length(); ++i) {
        if (aiText[i] == '\\' && i + 1 < aiText.length()) {
            if (aiText[i+1] == 'n') { cleanText += "\n"; i++; }
            else if (aiText[i+1] == 't') { cleanText += "\t"; i++; }
            else { cleanText += aiText[i]; }
        } else {
            cleanText += aiText[i];
        }
    }
    return cleanText.empty() ? "..." : cleanText;
}

int main() {
    // ВСТАВЬ СЮДА ТОКЕН ТВОЕГО НОВОГО БОТА
    string token("8785529784:AAFamqn-b_60iRsXtsECIZUZ5P64CS8Zf4s");
    Bot bot(token);

    bot.getEvents().onCommand("start", [&bot](Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Привет! Я ИИ-бот. Просто напиши мне что-нибудь.");
    });

    bot.getEvents().onAnyMessage([&bot](Message::Ptr message) {
        if (message->text.empty() || StringTools::startsWith(message->text, "/")) return;

        int64_t chatId = message->chat->id;
        
        // В группах реагируем только если бот упомянут или сообщение длинное
        auto typingStatus = bot.getApi().sendMessage(chatId, "🤔 Думаю...");
        
        try {
            string aiAnswer = askOllama(message->text);
            bot.getApi().deleteMessage(chatId, typingStatus->messageId);
            bot.getApi().sendMessage(chatId, aiAnswer);
        } catch (...) {
            bot.getApi().sendMessage(chatId, "❌ Ошибка ИИ.");
        }
    });

    try {
        cout << "Бот запущен!" << endl;
        TgLongPoll longPoll(bot);
        while (true) { longPoll.start(); }
    } catch (TgException& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
    return 0;
}