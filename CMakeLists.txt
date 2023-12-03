cmake_minimum_required(VERSION 3.5)
project(gra_ekonomiczna)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(gra_ekonomiczna ${SOURCES})
set_property(TARGET gra_ekonomiczna PROPERTY CXX_STANDARD 20)
target_include_directories(gra_ekonomiczna PUBLIC include)
target_compile_features(gra_ekonomiczna PUBLIC cxx_std_20)
