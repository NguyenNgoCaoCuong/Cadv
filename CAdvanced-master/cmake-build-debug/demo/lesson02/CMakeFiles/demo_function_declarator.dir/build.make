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
include demo/lesson02/CMakeFiles/demo_function_declarator.dir/depend.make

# Include the progress variables for this target.
include demo/lesson02/CMakeFiles/demo_function_declarator.dir/progress.make

# Include the compile flags for this target's objects.
include demo/lesson02/CMakeFiles/demo_function_declarator.dir/flags.make

demo/lesson02/CMakeFiles/demo_function_declarator.dir/function_declarator.c.o: demo/lesson02/CMakeFiles/demo_function_declarator.dir/flags.make
demo/lesson02/CMakeFiles/demo_function_declarator.dir/function_declarator.c.o: ../demo/lesson02/function_declarator.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object demo/lesson02/CMakeFiles/demo_function_declarator.dir/function_declarator.c.o"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson02 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/demo_function_declarator.dir/function_declarator.c.o   -c /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson02/function_declarator.c

demo/lesson02/CMakeFiles/demo_function_declarator.dir/function_declarator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/demo_function_declarator.dir/function_declarator.c.i"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson02 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson02/function_declarator.c > CMakeFiles/demo_function_declarator.dir/function_declarator.c.i

demo/lesson02/CMakeFiles/demo_function_declarator.dir/function_declarator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/demo_function_declarator.dir/function_declarator.c.s"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson02 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson02/function_declarator.c -o CMakeFiles/demo_function_declarator.dir/function_declarator.c.s

demo/lesson02/CMakeFiles/demo_function_declarator.dir/foo.c.o: demo/lesson02/CMakeFiles/demo_function_declarator.dir/flags.make
demo/lesson02/CMakeFiles/demo_function_declarator.dir/foo.c.o: ../demo/lesson02/foo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object demo/lesson02/CMakeFiles/demo_function_declarator.dir/foo.c.o"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson02 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/demo_function_declarator.dir/foo.c.o   -c /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson02/foo.c

demo/lesson02/CMakeFiles/demo_function_declarator.dir/foo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/demo_function_declarator.dir/foo.c.i"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson02 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson02/foo.c > CMakeFiles/demo_function_declarator.dir/foo.c.i

demo/lesson02/CMakeFiles/demo_function_declarator.dir/foo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/demo_function_declarator.dir/foo.c.s"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson02 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson02/foo.c -o CMakeFiles/demo_function_declarator.dir/foo.c.s

# Object files for target demo_function_declarator
demo_function_declarator_OBJECTS = \
"CMakeFiles/demo_function_declarator.dir/function_declarator.c.o" \
"CMakeFiles/demo_function_declarator.dir/foo.c.o"

# External object files for target demo_function_declarator
demo_function_declarator_EXTERNAL_OBJECTS =

demo/lesson02/demo_function_declarator: demo/lesson02/CMakeFiles/demo_function_declarator.dir/function_declarator.c.o
demo/lesson02/demo_function_declarator: demo/lesson02/CMakeFiles/demo_function_declarator.dir/foo.c.o
demo/lesson02/demo_function_declarator: demo/lesson02/CMakeFiles/demo_function_declarator.dir/build.make
demo/lesson02/demo_function_declarator: demo/lesson02/CMakeFiles/demo_function_declarator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable demo_function_declarator"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson02 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo_function_declarator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
demo/lesson02/CMakeFiles/demo_function_declarator.dir/build: demo/lesson02/demo_function_declarator

.PHONY : demo/lesson02/CMakeFiles/demo_function_declarator.dir/build

demo/lesson02/CMakeFiles/demo_function_declarator.dir/clean:
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson02 && $(CMAKE_COMMAND) -P CMakeFiles/demo_function_declarator.dir/cmake_clean.cmake
.PHONY : demo/lesson02/CMakeFiles/demo_function_declarator.dir/clean

demo/lesson02/CMakeFiles/demo_function_declarator.dir/depend:
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/CLionProjects/CAdvanced-master /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson02 /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson02 /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson02/CMakeFiles/demo_function_declarator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : demo/lesson02/CMakeFiles/demo_function_declarator.dir/depend
