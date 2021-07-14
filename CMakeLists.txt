cmake_minimum_required(VERSION 3.19)
project(iniparser)

set(CMAKE_CXX_STANDARD 20)

add_library(iniparser SHARED src/INIFile.cpp src/INIFile.h src/INISection.cpp src/INISection.h src/INIProp.cpp src/INIProp.h)
add_executable(testmain test/main.cpp)
target_link_libraries(testmain iniparser)