# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /mnt/d/code/cmpt473/googletest-exercise

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/code/cmpt473/googletest-exercise/build

# Include any dependencies generated for this target.
include test/lib/googlemock/gtest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include test/lib/googlemock/gtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include test/lib/googlemock/gtest/CMakeFiles/gtest.dir/flags.make

test/lib/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: test/lib/googlemock/gtest/CMakeFiles/gtest.dir/flags.make
test/lib/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../test/lib/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/code/cmpt473/googletest-exercise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/lib/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /mnt/d/code/cmpt473/googletest-exercise/build/test/lib/googlemock/gtest && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /mnt/d/code/cmpt473/googletest-exercise/test/lib/googletest/src/gtest-all.cc

test/lib/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /mnt/d/code/cmpt473/googletest-exercise/build/test/lib/googlemock/gtest && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/code/cmpt473/googletest-exercise/test/lib/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

test/lib/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /mnt/d/code/cmpt473/googletest-exercise/build/test/lib/googlemock/gtest && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/code/cmpt473/googletest-exercise/test/lib/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

test/lib/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires:

.PHONY : test/lib/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

test/lib/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides: test/lib/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires
	$(MAKE) -f test/lib/googlemock/gtest/CMakeFiles/gtest.dir/build.make test/lib/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build
.PHONY : test/lib/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides

test/lib/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.provides.build: test/lib/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o


# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtest.a: test/lib/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
lib/libgtest.a: test/lib/googlemock/gtest/CMakeFiles/gtest.dir/build.make
lib/libgtest.a: test/lib/googlemock/gtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/code/cmpt473/googletest-exercise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../../lib/libgtest.a"
	cd /mnt/d/code/cmpt473/googletest-exercise/build/test/lib/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /mnt/d/code/cmpt473/googletest-exercise/build/test/lib/googlemock/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/lib/googlemock/gtest/CMakeFiles/gtest.dir/build: lib/libgtest.a

.PHONY : test/lib/googlemock/gtest/CMakeFiles/gtest.dir/build

test/lib/googlemock/gtest/CMakeFiles/gtest.dir/requires: test/lib/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o.requires

.PHONY : test/lib/googlemock/gtest/CMakeFiles/gtest.dir/requires

test/lib/googlemock/gtest/CMakeFiles/gtest.dir/clean:
	cd /mnt/d/code/cmpt473/googletest-exercise/build/test/lib/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : test/lib/googlemock/gtest/CMakeFiles/gtest.dir/clean

test/lib/googlemock/gtest/CMakeFiles/gtest.dir/depend:
	cd /mnt/d/code/cmpt473/googletest-exercise/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/code/cmpt473/googletest-exercise /mnt/d/code/cmpt473/googletest-exercise/test/lib/googletest /mnt/d/code/cmpt473/googletest-exercise/build /mnt/d/code/cmpt473/googletest-exercise/build/test/lib/googlemock/gtest /mnt/d/code/cmpt473/googletest-exercise/build/test/lib/googlemock/gtest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/lib/googlemock/gtest/CMakeFiles/gtest.dir/depend
