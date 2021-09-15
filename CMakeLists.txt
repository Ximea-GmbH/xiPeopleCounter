cmake_minimum_required(VERSION 3.20)
project(xiPeopleCounter
        VERSION 1.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(xiApiPlusOcv)
add_subdirectory(src)

