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
include demo/lesson04/CMakeFiles/test_dllist.dir/depend.make

# Include the progress variables for this target.
include demo/lesson04/CMakeFiles/test_dllist.dir/progress.make

# Include the compile flags for this target's objects.
include demo/lesson04/CMakeFiles/test_dllist.dir/flags.make

demo/lesson04/CMakeFiles/test_dllist.dir/test_dllist.c.o: demo/lesson04/CMakeFiles/test_dllist.dir/flags.make
demo/lesson04/CMakeFiles/test_dllist.dir/test_dllist.c.o: ../demo/lesson04/test_dllist.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object demo/lesson04/CMakeFiles/test_dllist.dir/test_dllist.c.o"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson04 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_dllist.dir/test_dllist.c.o   -c /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson04/test_dllist.c

demo/lesson04/CMakeFiles/test_dllist.dir/test_dllist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_dllist.dir/test_dllist.c.i"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson04 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson04/test_dllist.c > CMakeFiles/test_dllist.dir/test_dllist.c.i

demo/lesson04/CMakeFiles/test_dllist.dir/test_dllist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_dllist.dir/test_dllist.c.s"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson04 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson04/test_dllist.c -o CMakeFiles/test_dllist.dir/test_dllist.c.s

# Object files for target test_dllist
test_dllist_OBJECTS = \
"CMakeFiles/test_dllist.dir/test_dllist.c.o"

# External object files for target test_dllist
test_dllist_EXTERNAL_OBJECTS =

demo/lesson04/test_dllist: demo/lesson04/CMakeFiles/test_dllist.dir/test_dllist.c.o
demo/lesson04/test_dllist: demo/lesson04/CMakeFiles/test_dllist.dir/build.make
demo/lesson04/test_dllist: DebugPrintf/libdebug_printf.a
demo/lesson04/test_dllist: GRAPH/libfdr/libfdr.a
demo/lesson04/test_dllist: demo/lesson04/CMakeFiles/test_dllist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test_dllist"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson04 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_dllist.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
demo/lesson04/CMakeFiles/test_dllist.dir/build: demo/lesson04/test_dllist

.PHONY : demo/lesson04/CMakeFiles/test_dllist.dir/build

demo/lesson04/CMakeFiles/test_dllist.dir/clean:
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson04 && $(CMAKE_COMMAND) -P CMakeFiles/test_dllist.dir/cmake_clean.cmake
.PHONY : demo/lesson04/CMakeFiles/test_dllist.dir/clean

demo/lesson04/CMakeFiles/test_dllist.dir/depend:
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/CLionProjects/CAdvanced-master /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson04 /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson04 /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson04/CMakeFiles/test_dllist.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : demo/lesson04/CMakeFiles/test_dllist.dir/depend

