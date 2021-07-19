cmake_minimum_required(VERSION 3.19)
project(iniparser)

set(CMAKE_CXX_STANDARD 20)
set(gtest_SOURCE_DIR, ./lib/googletest/)
set(TEST_SOURCE_FILES test/runAllTest.cpp test/INIFileFixture.cpp)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_subdirectory(./test/lib/googletest)
add_library(iniparser SHARED src/INIFile.cpp src/INIFile.h src/INISection.cpp src/INISection.h src/INIProp.h src/utility.h)
add_executable(runtest ${TEST_SOURCE_FILES})
target_link_libraries(runtest iniparser gtest gtest_main)


