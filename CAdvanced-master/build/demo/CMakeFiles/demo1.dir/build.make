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
include demo/CMakeFiles/demo1.dir/depend.make

# Include the progress variables for this target.
include demo/CMakeFiles/demo1.dir/progress.make

# Include the compile flags for this target's objects.
include demo/CMakeFiles/demo1.dir/flags.make

demo/CMakeFiles/demo1.dir/demo1.c.o: demo/CMakeFiles/demo1.dir/flags.make
demo/CMakeFiles/demo1.dir/demo1.c.o: ../demo/demo1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/CLionProjects/CAdvanced-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object demo/CMakeFiles/demo1.dir/demo1.c.o"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build/demo && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/demo1.dir/demo1.c.o   -c /home/ubuntu/CLionProjects/CAdvanced-master/demo/demo1.c

demo/CMakeFiles/demo1.dir/demo1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/demo1.dir/demo1.c.i"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build/demo && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/CLionProjects/CAdvanced-master/demo/demo1.c > CMakeFiles/demo1.dir/demo1.c.i

demo/CMakeFiles/demo1.dir/demo1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/demo1.dir/demo1.c.s"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build/demo && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/CLionProjects/CAdvanced-master/demo/demo1.c -o CMakeFiles/demo1.dir/demo1.c.s

# Object files for target demo1
demo1_OBJECTS = \
"CMakeFiles/demo1.dir/demo1.c.o"

# External object files for target demo1
demo1_EXTERNAL_OBJECTS =

demo/demo1: demo/CMakeFiles/demo1.dir/demo1.c.o
demo/demo1: demo/CMakeFiles/demo1.dir/build.make
demo/demo1: libfdr/libfdr.a
demo/demo1: demo/CMakeFiles/demo1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/CLionProjects/CAdvanced-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable demo1"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build/demo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
demo/CMakeFiles/demo1.dir/build: demo/demo1

.PHONY : demo/CMakeFiles/demo1.dir/build

demo/CMakeFiles/demo1.dir/clean:
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build/demo && $(CMAKE_COMMAND) -P CMakeFiles/demo1.dir/cmake_clean.cmake
.PHONY : demo/CMakeFiles/demo1.dir/clean

demo/CMakeFiles/demo1.dir/depend:
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/CLionProjects/CAdvanced-master /home/ubuntu/CLionProjects/CAdvanced-master/demo /home/ubuntu/CLionProjects/CAdvanced-master/build /home/ubuntu/CLionProjects/CAdvanced-master/build/demo /home/ubuntu/CLionProjects/CAdvanced-master/build/demo/CMakeFiles/demo1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : demo/CMakeFiles/demo1.dir/depend

