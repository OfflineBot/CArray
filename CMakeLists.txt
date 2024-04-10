cmake_minimum_required(VERSION 3.22)
project(correct_carray)

set(CMAKE_CXX_STANDARD 17)

add_executable(main
        main.cpp
        carray/carray1/immutable/argmax.hpp
        carray/functions/methods/argmax.hpp
        carray/functions/methods/max.hpp
)