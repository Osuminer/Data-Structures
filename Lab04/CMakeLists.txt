project(Lab04)
cmake_minimum_required(VERSION 3.1)

find_package(GTest REQUIRED)
 
add_library(applibrary main.cpp)

# runTests
add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread applibrary)

# runMain
add_executable(runMain main.cpp)
target_link_libraries(runMain applibrary)