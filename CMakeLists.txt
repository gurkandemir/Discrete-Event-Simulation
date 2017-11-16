cmake_minimum_required(VERSION 3.8)
project(Project2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Customer.h Customer.cpp Cashier.h Cashier.cpp Barista.h Barista.cpp main.cpp)
add_executable(Project2 ${SOURCE_FILES})