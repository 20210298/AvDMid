cmake_minimum_required(VERSION 3.29)
project(AvDMid)

set(CMAKE_CXX_STANDARD 20)

add_executable(AvDMid main.cpp
        NQueenSolver.h
        NQueenSolverByBitMask.h
        NQueenSolver.cpp
        NQueenSolverByBitMask.cpp)
