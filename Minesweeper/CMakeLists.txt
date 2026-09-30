cmake_minimum_required(VERSION 3.15)
project(MinesweeperApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(Minesweeper main.cpp)

target_link_libraries(Minesweeper ${wxWidgets_LIBRARIES})