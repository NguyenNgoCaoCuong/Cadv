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
include demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/depend.make

# Include the progress variables for this target.
include demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/progress.make

# Include the compile flags for this target's objects.
include demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/flags.make

demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/jrb_strsort_pipe.c.o: demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/flags.make
demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/jrb_strsort_pipe.c.o: ../demo/lesson05/jrb_strsort_pipe.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/jrb_strsort_pipe.c.o"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson05 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/jrb_strsort_pipe.dir/jrb_strsort_pipe.c.o   -c /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson05/jrb_strsort_pipe.c

demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/jrb_strsort_pipe.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jrb_strsort_pipe.dir/jrb_strsort_pipe.c.i"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson05 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson05/jrb_strsort_pipe.c > CMakeFiles/jrb_strsort_pipe.dir/jrb_strsort_pipe.c.i

demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/jrb_strsort_pipe.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jrb_strsort_pipe.dir/jrb_strsort_pipe.c.s"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson05 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson05/jrb_strsort_pipe.c -o CMakeFiles/jrb_strsort_pipe.dir/jrb_strsort_pipe.c.s

# Object files for target jrb_strsort_pipe
jrb_strsort_pipe_OBJECTS = \
"CMakeFiles/jrb_strsort_pipe.dir/jrb_strsort_pipe.c.o"

# External object files for target jrb_strsort_pipe
jrb_strsort_pipe_EXTERNAL_OBJECTS =

demo/lesson05/jrb_strsort_pipe: demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/jrb_strsort_pipe.c.o
demo/lesson05/jrb_strsort_pipe: demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/build.make
demo/lesson05/jrb_strsort_pipe: GRAPH/libfdr/libfdr.a
demo/lesson05/jrb_strsort_pipe: demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable jrb_strsort_pipe"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson05 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/jrb_strsort_pipe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/build: demo/lesson05/jrb_strsort_pipe

.PHONY : demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/build

demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/clean:
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson05 && $(CMAKE_COMMAND) -P CMakeFiles/jrb_strsort_pipe.dir/cmake_clean.cmake
.PHONY : demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/clean

demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/depend:
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/CLionProjects/CAdvanced-master /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson05 /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson05 /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : demo/lesson05/CMakeFiles/jrb_strsort_pipe.dir/depend
