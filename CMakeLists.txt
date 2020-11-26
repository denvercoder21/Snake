cmake_minimum_required(VERSION 3.16)

project(snake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -pedantic -Werror)

find_package(Threads REQUIRED)
find_package(Qt5 COMPONENTS Core Qml Quick REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(snake
    src/main.cpp
    src/model/board.cpp
    src/model/game.cpp
    src/model/snake.cpp
    src/viewmodel/board_viewmodel.cpp
    src/viewmodel/snake_viewmodel.cpp

    res/qml.qrc
)

target_include_directories(snake
    PRIVATE
        src/
)

target_link_libraries(snake
        Threads::Threads
        Qt5::Core
        Qt5::Qml
        Qt5::Quick
)
