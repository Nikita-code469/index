cmake_minimum_required(VERSION 3.15)
project(tg_ai_bot CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Пути поиска для заголовков и библиотек Homebrew
include_directories(/opt/homebrew/include /usr/local/include)
link_directories(/opt/homebrew/lib /usr/local/lib)

find_package(TgBot REQUIRED)
find_package(OpenSSL REQUIRED)

add_executable(tg_ai_bot main.cpp)

target_link_libraries(tg_ai_bot PRIVATE 
    TgBot 
    OpenSSL::SSL 
    OpenSSL::Crypto
)