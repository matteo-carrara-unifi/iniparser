cmake_minimum_required(VERSION 3.19)
project(iniparser)

set(CMAKE_CXX_STANDARD 20)

add_library(iniparser SHARED INIParser.cpp INIParser.h INISection.cpp INISection.h INIValue.cpp INIValue.h)
add_executable(testmain main.cpp)
target_link_libraries(testmain iniparser)