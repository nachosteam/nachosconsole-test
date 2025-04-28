cmake_minimum_required(VERSION 3.5)
project(nc-test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2 -Wextra -static -lstdc++fs -std=c++23")

set(SOURCE_FILES src/main.cpp
                 src/SHA512.cpp)

add_executable(nachos-console ${SOURCE_FILES})
