# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/ubuntu/CLionProjects/CAdvanced-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/CLionProjects/CAdvanced-master/build

# Include any dependencies generated for this target.
include myTest/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include myTest/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include myTest/CMakeFiles/main.dir/flags.make

myTest/CMakeFiles/main.dir/main.c.o: myTest/CMakeFiles/main.dir/flags.make
myTest/CMakeFiles/main.dir/main.c.o: ../myTest/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/CLionProjects/CAdvanced-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object myTest/CMakeFiles/main.dir/main.c.o"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build/myTest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/main.c.o   -c /home/ubuntu/CLionProjects/CAdvanced-master/myTest/main.c

myTest/CMakeFiles/main.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/main.c.i"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build/myTest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/CLionProjects/CAdvanced-master/myTest/main.c > CMakeFiles/main.dir/main.c.i

myTest/CMakeFiles/main.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/main.c.s"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build/myTest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/CLionProjects/CAdvanced-master/myTest/main.c -o CMakeFiles/main.dir/main.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

myTest/main: myTest/CMakeFiles/main.dir/main.c.o
myTest/main: myTest/CMakeFiles/main.dir/build.make
myTest/main: ../binaries/libigraph.a
myTest/main: GRAPH/libfdr/libfdr.a
myTest/main: myTest/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/CLionProjects/CAdvanced-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable main"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build/myTest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
myTest/CMakeFiles/main.dir/build: myTest/main

.PHONY : myTest/CMakeFiles/main.dir/build

myTest/CMakeFiles/main.dir/clean:
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build/myTest && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : myTest/CMakeFiles/main.dir/clean

myTest/CMakeFiles/main.dir/depend:
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/CLionProjects/CAdvanced-master /home/ubuntu/CLionProjects/CAdvanced-master/myTest /home/ubuntu/CLionProjects/CAdvanced-master/build /home/ubuntu/CLionProjects/CAdvanced-master/build/myTest /home/ubuntu/CLionProjects/CAdvanced-master/build/myTest/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : myTest/CMakeFiles/main.dir/depend

