cmake_minimum_required(VERSION 3.0)

project(cppmod)
set(PYBIND11_CPP_STANDARD -std=c++14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2")
add_subdirectory(pybind11)

pybind11_add_module(cppmod SHARED cppmod.cpp)


project(cppdistance)
set(PYBIND11_CPP_STANDARD -std=c++14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2")

pybind11_add_module(cppdistance SHARED cppdistance.cpp)