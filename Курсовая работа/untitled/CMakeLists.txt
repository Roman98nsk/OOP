cmake_minimum_required(VERSION 3.19)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5.1 COMPONENTS graphics)

add_executable(untitled Box.cpp Cross.cpp Figure.cpp GameState.cpp Laticce.cpp Menu.cpp Opacity.cpp Zero.cpp Main.cpp Box.h Cross.h Figure.h GameState.h Laticce.h Menu.h Opacity.h Zero.h)

target_link_libraries(untitled sfml-graphics)