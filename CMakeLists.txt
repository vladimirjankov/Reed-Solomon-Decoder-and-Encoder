cmake_minimum_required(VERSION 3.15)
project(untitled6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -O3")

include_directories(./)

add_executable(untitled6 encoding/coder.cpp encoding/decoder.cpp
                         field_element/element.cpp field_element/polynome.cpp
                         utility/fourier33.cpp utility/fourier1023.cpp utility/utility_functions.cpp main.cpp)