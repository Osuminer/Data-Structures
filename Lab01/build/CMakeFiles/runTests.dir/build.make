# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
<<<<<<< HEAD
CMAKE_SOURCE_DIR = /home/connor/Desktop/Data-Structures/Lab01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/connor/Desktop/Data-Structures/Lab01/build
=======
CMAKE_SOURCE_DIR = /home/user/Desktop/Data-Structures/Lab01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/Desktop/Data-Structures/Lab01/build
>>>>>>> 77a0f445d83f442a11c70c141cd9f5749db33b72

# Include any dependencies generated for this target.
include CMakeFiles/runTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/runTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/runTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runTests.dir/flags.make

CMakeFiles/runTests.dir/tests.cpp.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/tests.cpp.o: ../tests.cpp
CMakeFiles/runTests.dir/tests.cpp.o: CMakeFiles/runTests.dir/compiler_depend.ts
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/connor/Desktop/Data-Structures/Lab01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runTests.dir/tests.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runTests.dir/tests.cpp.o -MF CMakeFiles/runTests.dir/tests.cpp.o.d -o CMakeFiles/runTests.dir/tests.cpp.o -c /home/connor/Desktop/Data-Structures/Lab01/tests.cpp

CMakeFiles/runTests.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/tests.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/connor/Desktop/Data-Structures/Lab01/tests.cpp > CMakeFiles/runTests.dir/tests.cpp.i

CMakeFiles/runTests.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/tests.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/connor/Desktop/Data-Structures/Lab01/tests.cpp -o CMakeFiles/runTests.dir/tests.cpp.s
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Desktop/Data-Structures/Lab01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runTests.dir/tests.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runTests.dir/tests.cpp.o -MF CMakeFiles/runTests.dir/tests.cpp.o.d -o CMakeFiles/runTests.dir/tests.cpp.o -c /home/user/Desktop/Data-Structures/Lab01/tests.cpp

CMakeFiles/runTests.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/tests.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Desktop/Data-Structures/Lab01/tests.cpp > CMakeFiles/runTests.dir/tests.cpp.i

CMakeFiles/runTests.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/tests.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Desktop/Data-Structures/Lab01/tests.cpp -o CMakeFiles/runTests.dir/tests.cpp.s
>>>>>>> 77a0f445d83f442a11c70c141cd9f5749db33b72

# Object files for target runTests
runTests_OBJECTS = \
"CMakeFiles/runTests.dir/tests.cpp.o"

# External object files for target runTests
runTests_EXTERNAL_OBJECTS =

runTests: CMakeFiles/runTests.dir/tests.cpp.o
runTests: CMakeFiles/runTests.dir/build.make
runTests: /usr/lib/x86_64-linux-gnu/libgtest.a
runTests: libapplibrary.a
runTests: CMakeFiles/runTests.dir/link.txt
<<<<<<< HEAD
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/connor/Desktop/Data-Structures/Lab01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable runTests"
=======
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/Desktop/Data-Structures/Lab01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable runTests"
>>>>>>> 77a0f445d83f442a11c70c141cd9f5749db33b72
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runTests.dir/build: runTests
.PHONY : CMakeFiles/runTests.dir/build

CMakeFiles/runTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runTests.dir/clean

CMakeFiles/runTests.dir/depend:
<<<<<<< HEAD
	cd /home/connor/Desktop/Data-Structures/Lab01/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/connor/Desktop/Data-Structures/Lab01 /home/connor/Desktop/Data-Structures/Lab01 /home/connor/Desktop/Data-Structures/Lab01/build /home/connor/Desktop/Data-Structures/Lab01/build /home/connor/Desktop/Data-Structures/Lab01/build/CMakeFiles/runTests.dir/DependInfo.cmake --color=$(COLOR)
=======
	cd /home/user/Desktop/Data-Structures/Lab01/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/Desktop/Data-Structures/Lab01 /home/user/Desktop/Data-Structures/Lab01 /home/user/Desktop/Data-Structures/Lab01/build /home/user/Desktop/Data-Structures/Lab01/build /home/user/Desktop/Data-Structures/Lab01/build/CMakeFiles/runTests.dir/DependInfo.cmake --color=$(COLOR)
>>>>>>> 77a0f445d83f442a11c70c141cd9f5749db33b72
.PHONY : CMakeFiles/runTests.dir/depend

