# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kantokuleo/Documents/CMPT473/msgpack-c-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build

# Include any dependencies generated for this target.
include example/cpp03/CMakeFiles/simple.dir/depend.make

# Include the progress variables for this target.
include example/cpp03/CMakeFiles/simple.dir/progress.make

# Include the compile flags for this target's objects.
include example/cpp03/CMakeFiles/simple.dir/flags.make

example/cpp03/CMakeFiles/simple.dir/simple.cpp.o: example/cpp03/CMakeFiles/simple.dir/flags.make
example/cpp03/CMakeFiles/simple.dir/simple.cpp.o: ../example/cpp03/simple.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object example/cpp03/CMakeFiles/simple.dir/simple.cpp.o"
	cd /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/example/cpp03 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple.dir/simple.cpp.o -c /home/kantokuleo/Documents/CMPT473/msgpack-c-master/example/cpp03/simple.cpp

example/cpp03/CMakeFiles/simple.dir/simple.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple.dir/simple.cpp.i"
	cd /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/example/cpp03 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kantokuleo/Documents/CMPT473/msgpack-c-master/example/cpp03/simple.cpp > CMakeFiles/simple.dir/simple.cpp.i

example/cpp03/CMakeFiles/simple.dir/simple.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple.dir/simple.cpp.s"
	cd /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/example/cpp03 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kantokuleo/Documents/CMPT473/msgpack-c-master/example/cpp03/simple.cpp -o CMakeFiles/simple.dir/simple.cpp.s

# Object files for target simple
simple_OBJECTS = \
"CMakeFiles/simple.dir/simple.cpp.o"

# External object files for target simple
simple_EXTERNAL_OBJECTS =

example/cpp03/simple: example/cpp03/CMakeFiles/simple.dir/simple.cpp.o
example/cpp03/simple: example/cpp03/CMakeFiles/simple.dir/build.make
example/cpp03/simple: example/cpp03/CMakeFiles/simple.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable simple"
	cd /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/example/cpp03 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
example/cpp03/CMakeFiles/simple.dir/build: example/cpp03/simple

.PHONY : example/cpp03/CMakeFiles/simple.dir/build

example/cpp03/CMakeFiles/simple.dir/clean:
	cd /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/example/cpp03 && $(CMAKE_COMMAND) -P CMakeFiles/simple.dir/cmake_clean.cmake
.PHONY : example/cpp03/CMakeFiles/simple.dir/clean

example/cpp03/CMakeFiles/simple.dir/depend:
	cd /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kantokuleo/Documents/CMPT473/msgpack-c-master /home/kantokuleo/Documents/CMPT473/msgpack-c-master/example/cpp03 /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/example/cpp03 /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/example/cpp03/CMakeFiles/simple.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : example/cpp03/CMakeFiles/simple.dir/depend

