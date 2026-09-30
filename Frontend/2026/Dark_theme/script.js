// 1. Находим кнопку по ее ID
const a = document.getElementById('a');

// 2. Добавляем слушатель клика
a.addEventListener('click', () => {
    // Переключаем класс 'a1' у элемента <body>
    document.body.classList.toggle('a1');

    // Проверяем, включена ли сейчас тёмная тема, и меняем текст на кнопке
    if (document.body.classList.contains('a1')) {
        a.textContent = '☀️ Светлая тема';
    } else {
        a.textContent = '🌙 Тёмная тема';
    }
});