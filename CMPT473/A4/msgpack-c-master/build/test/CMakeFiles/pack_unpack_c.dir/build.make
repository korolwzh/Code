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
include test/CMakeFiles/pack_unpack_c.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/pack_unpack_c.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/pack_unpack_c.dir/flags.make

test/CMakeFiles/pack_unpack_c.dir/pack_unpack_c.cpp.o: test/CMakeFiles/pack_unpack_c.dir/flags.make
test/CMakeFiles/pack_unpack_c.dir/pack_unpack_c.cpp.o: ../test/pack_unpack_c.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/pack_unpack_c.dir/pack_unpack_c.cpp.o"
	cd /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pack_unpack_c.dir/pack_unpack_c.cpp.o -c /home/kantokuleo/Documents/CMPT473/msgpack-c-master/test/pack_unpack_c.cpp

test/CMakeFiles/pack_unpack_c.dir/pack_unpack_c.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pack_unpack_c.dir/pack_unpack_c.cpp.i"
	cd /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kantokuleo/Documents/CMPT473/msgpack-c-master/test/pack_unpack_c.cpp > CMakeFiles/pack_unpack_c.dir/pack_unpack_c.cpp.i

test/CMakeFiles/pack_unpack_c.dir/pack_unpack_c.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pack_unpack_c.dir/pack_unpack_c.cpp.s"
	cd /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kantokuleo/Documents/CMPT473/msgpack-c-master/test/pack_unpack_c.cpp -o CMakeFiles/pack_unpack_c.dir/pack_unpack_c.cpp.s

# Object files for target pack_unpack_c
pack_unpack_c_OBJECTS = \
"CMakeFiles/pack_unpack_c.dir/pack_unpack_c.cpp.o"

# External object files for target pack_unpack_c
pack_unpack_c_EXTERNAL_OBJECTS =

test/pack_unpack_c: test/CMakeFiles/pack_unpack_c.dir/pack_unpack_c.cpp.o
test/pack_unpack_c: test/CMakeFiles/pack_unpack_c.dir/build.make
test/pack_unpack_c: libmsgpackc.so.2.0.0
test/pack_unpack_c: /usr/lib/x86_64-linux-gnu/libgtest.a
test/pack_unpack_c: /usr/lib/x86_64-linux-gnu/libgtest_main.a
test/pack_unpack_c: /usr/lib/x86_64-linux-gnu/libz.so
test/pack_unpack_c: test/CMakeFiles/pack_unpack_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pack_unpack_c"
	cd /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pack_unpack_c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/pack_unpack_c.dir/build: test/pack_unpack_c

.PHONY : test/CMakeFiles/pack_unpack_c.dir/build

test/CMakeFiles/pack_unpack_c.dir/clean:
	cd /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/test && $(CMAKE_COMMAND) -P CMakeFiles/pack_unpack_c.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/pack_unpack_c.dir/clean

test/CMakeFiles/pack_unpack_c.dir/depend:
	cd /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kantokuleo/Documents/CMPT473/msgpack-c-master /home/kantokuleo/Documents/CMPT473/msgpack-c-master/test /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/test /home/kantokuleo/Documents/CMPT473/msgpack-c-master/build/test/CMakeFiles/pack_unpack_c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/pack_unpack_c.dir/depend

