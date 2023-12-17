cmake_minimum_required(VERSION 3.27)
project(redo)

set(CMAKE_CXX_STANDARD 17)

add_executable(redo
        include/BoardGame_Classes.hpp
        xo/GameManager.cpp
        xo/RandomPlayer.cpp
        xo/Player.cpp
        xo/X_O_Board.cpp
        xo/X_O_Runner.cpp
        app.cpp
        Tic_Tac_Teo/Tic_Tac_Teo_Board.cpp
        Tic_Tac_Teo/Tic_Tac_Teo_GameManager.cpp
        Tic_Tac_Teo/Tic_Tac_Teo_Runner.cpp
        "connect 4/fourByfour.cpp"
        "connect 4/fourByfour_RandomPlayer.cpp"
        "connect 4/run_Connect4.cpp"
        pyramic/Pyramic_Random_Player.cpp
        pyramic/Pyramic_XO_Board.cpp
        pyramic/run_pyramic.cpp)
