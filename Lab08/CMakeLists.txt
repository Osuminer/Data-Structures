cmake_minimum_required(VERSION 3.0)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library (applibrary SHARED Barbarian.cpp Dwarf.cpp Elf.cpp Game.cpp Gigachad.cpp Halfling.cpp
             Human.cpp Monk.cpp Paladin.cpp Wizard.cpp Party.cpp CharacterFactory.cpp)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread applibrary) 

add_executable(runMain Game.cpp)
target_link_libraries(runMain applibrary)