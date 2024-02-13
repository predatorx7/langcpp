cmake_minimum_required (VERSION 3.2 FATAL_ERROR)

project(Solution)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY build/bin/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY build/bin/lib)

file(GLOB solution_SRC CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")

add_executable(Solution ${solution_SRC})
