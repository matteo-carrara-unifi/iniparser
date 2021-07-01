cmake_minimum_required(VERSION 3.19)
project(iniparser)

set(CMAKE_CXX_STANDARD 20)

add_library(iniparser SHARED src/INIParser.cpp src/INIParser.h src/INISection.cpp src/INISection.h src/INIValue.cpp src/INIValue.h)
add_executable(testmain test/main.cpp)
target_link_libraries(testmain iniparser)