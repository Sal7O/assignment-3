cmake_minimum_required(VERSION 3.27)
project(final)

set(CMAKE_CXX_STANDARD 17)

add_executable(final
        App.cpp
        include/BoardGame_classes.hpp
        X_O/src/GameManager.cpp
        X_O/src/GameRunner.cpp
        X_O/src/Player.cpp
        X_O/src/RandomPlayer.cpp
        X_O/src/X_O_Board.cpp

)
