cmake_minimum_required(VERSION 3.23)
project(Tic_Tac_Toe)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tic_Tac_Toe
        Tic-Tac-Toe/main.cpp
        Tic-Tac-Toe/Player.cpp
        Tic-Tac-Toe/Statistic.cpp)
