cmake_minimum_required(VERSION 3.23)
project(Fraction_a)

set(CMAKE_CXX_STANDARD 14)

add_executable(Fraction_a Demo.cpp ./sources/Fraction.cpp ./sources/Fraction.hpp Test.cpp TestCounter.cpp)
