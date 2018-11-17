cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 14)  # enable C++14 standard

project(symbstat)

#add headers to project
FILE(GLOB_RECURSE LibFiles "*.h")
add_custom_target(headers SOURCES ${LibFiles})

#add executables
add_executable(${PROJECT_NAME} main.cpp filewrapper.cpp argsparser.cpp)
