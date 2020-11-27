cmake_minimum_required(VERSION 3.5)
# set the project name
project(pipestatus)

# add the executable
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wpedantic -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
file (GLOB source_files "${source_dir}/*.cpp")
add_executable(pipestatus ${source_files})
