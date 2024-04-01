cmake_minimum_required(VERSION 3.27)
project(LinkedLabyrinth)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LinkedLabyrinth
        Labyrinth.cpp
        Labyrinth.hpp
        Main.cpp
        MazeGenerator.cpp
        MazeGenerator.hpp)

