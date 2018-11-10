cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 14)  # enable C++14 standard

project(symbstat)
add_executable(${PROJECT_NAME} main.cpp filewrapper.cpp argsparser.cpp)
include_directories( ${MY_SOURCE_DIR} )
