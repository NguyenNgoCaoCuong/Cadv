# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/ubuntu/Downloads/clion-2020.1.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ubuntu/Downloads/clion-2020.1.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/CLionProjects/CAdvanced-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug

# Include any dependencies generated for this target.
include demo/lesson04/CMakeFiles/dllist_demo.dir/depend.make

# Include the progress variables for this target.
include demo/lesson04/CMakeFiles/dllist_demo.dir/progress.make

# Include the compile flags for this target's objects.
include demo/lesson04/CMakeFiles/dllist_demo.dir/flags.make

demo/lesson04/CMakeFiles/dllist_demo.dir/dllist_demo.c.o: demo/lesson04/CMakeFiles/dllist_demo.dir/flags.make
demo/lesson04/CMakeFiles/dllist_demo.dir/dllist_demo.c.o: ../demo/lesson04/dllist_demo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object demo/lesson04/CMakeFiles/dllist_demo.dir/dllist_demo.c.o"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson04 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dllist_demo.dir/dllist_demo.c.o   -c /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson04/dllist_demo.c

demo/lesson04/CMakeFiles/dllist_demo.dir/dllist_demo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dllist_demo.dir/dllist_demo.c.i"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson04 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson04/dllist_demo.c > CMakeFiles/dllist_demo.dir/dllist_demo.c.i

demo/lesson04/CMakeFiles/dllist_demo.dir/dllist_demo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dllist_demo.dir/dllist_demo.c.s"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson04 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson04/dllist_demo.c -o CMakeFiles/dllist_demo.dir/dllist_demo.c.s

# Object files for target dllist_demo
dllist_demo_OBJECTS = \
"CMakeFiles/dllist_demo.dir/dllist_demo.c.o"

# External object files for target dllist_demo
dllist_demo_EXTERNAL_OBJECTS =

demo/lesson04/dllist_demo: demo/lesson04/CMakeFiles/dllist_demo.dir/dllist_demo.c.o
demo/lesson04/dllist_demo: demo/lesson04/CMakeFiles/dllist_demo.dir/build.make
demo/lesson04/dllist_demo: DebugPrintf/libdebug_printf.a
demo/lesson04/dllist_demo: GRAPH/libfdr/libfdr.a
demo/lesson04/dllist_demo: demo/lesson04/CMakeFiles/dllist_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable dllist_demo"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson04 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dllist_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
demo/lesson04/CMakeFiles/dllist_demo.dir/build: demo/lesson04/dllist_demo

.PHONY : demo/lesson04/CMakeFiles/dllist_demo.dir/build

demo/lesson04/CMakeFiles/dllist_demo.dir/clean:
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson04 && $(CMAKE_COMMAND) -P CMakeFiles/dllist_demo.dir/cmake_clean.cmake
.PHONY : demo/lesson04/CMakeFiles/dllist_demo.dir/clean

demo/lesson04/CMakeFiles/dllist_demo.dir/depend:
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/CLionProjects/CAdvanced-master /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson04 /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson04 /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson04/CMakeFiles/dllist_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : demo/lesson04/CMakeFiles/dllist_demo.dir/depend
