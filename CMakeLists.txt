cmake_minimum_required(VERSION 3.8)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 17)

# Add include directory (which contains project header files)
include_directories("./include")
# Add a subdirectory which is the source directory (which contains project source files)
add_subdirectory("./src")
