cmake_minimum_required(VERSION 3.0)

project(Knapsack)
set(PYBIND11_CPP_STANDARD -std=c++17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2")
add_subdirectory(pybind11)

pybind11_add_module(Knapsack SHARED Knapsack.cpp)