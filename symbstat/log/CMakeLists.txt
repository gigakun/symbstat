cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 14)  # enable C++14 standard

project(log)

#add headers to project
#FILE(GLOB_RECURSE LogLibFiles "*.h")
#add_custom_target(headers SOURCES ${LibFiles})
#add headers to project
FILE(GLOB LibFiles "*.h")
add_custom_target(${PROJECT_NAME}_headers SOURCES ${LibFiles})

#add executables
add_executable(${PROJECT_NAME} log.cpp)
