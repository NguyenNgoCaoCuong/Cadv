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
include DebugPrintf/CMakeFiles/debug_printf.dir/depend.make

# Include the progress variables for this target.
include DebugPrintf/CMakeFiles/debug_printf.dir/progress.make

# Include the compile flags for this target's objects.
include DebugPrintf/CMakeFiles/debug_printf.dir/flags.make

DebugPrintf/CMakeFiles/debug_printf.dir/debug_printf.c.o: DebugPrintf/CMakeFiles/debug_printf.dir/flags.make
DebugPrintf/CMakeFiles/debug_printf.dir/debug_printf.c.o: ../DebugPrintf/debug_printf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/CLionProjects/CAdvanced-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object DebugPrintf/CMakeFiles/debug_printf.dir/debug_printf.c.o"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build/DebugPrintf && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/debug_printf.dir/debug_printf.c.o   -c /home/ubuntu/CLionProjects/CAdvanced-master/DebugPrintf/debug_printf.c

DebugPrintf/CMakeFiles/debug_printf.dir/debug_printf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/debug_printf.dir/debug_printf.c.i"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build/DebugPrintf && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/CLionProjects/CAdvanced-master/DebugPrintf/debug_printf.c > CMakeFiles/debug_printf.dir/debug_printf.c.i

DebugPrintf/CMakeFiles/debug_printf.dir/debug_printf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/debug_printf.dir/debug_printf.c.s"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build/DebugPrintf && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/CLionProjects/CAdvanced-master/DebugPrintf/debug_printf.c -o CMakeFiles/debug_printf.dir/debug_printf.c.s

# Object files for target debug_printf
debug_printf_OBJECTS = \
"CMakeFiles/debug_printf.dir/debug_printf.c.o"

# External object files for target debug_printf
debug_printf_EXTERNAL_OBJECTS =

DebugPrintf/libdebug_printf.a: DebugPrintf/CMakeFiles/debug_printf.dir/debug_printf.c.o
DebugPrintf/libdebug_printf.a: DebugPrintf/CMakeFiles/debug_printf.dir/build.make
DebugPrintf/libdebug_printf.a: DebugPrintf/CMakeFiles/debug_printf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/CLionProjects/CAdvanced-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libdebug_printf.a"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build/DebugPrintf && $(CMAKE_COMMAND) -P CMakeFiles/debug_printf.dir/cmake_clean_target.cmake
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build/DebugPrintf && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/debug_printf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
DebugPrintf/CMakeFiles/debug_printf.dir/build: DebugPrintf/libdebug_printf.a

.PHONY : DebugPrintf/CMakeFiles/debug_printf.dir/build

DebugPrintf/CMakeFiles/debug_printf.dir/clean:
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build/DebugPrintf && $(CMAKE_COMMAND) -P CMakeFiles/debug_printf.dir/cmake_clean.cmake
.PHONY : DebugPrintf/CMakeFiles/debug_printf.dir/clean

DebugPrintf/CMakeFiles/debug_printf.dir/depend:
	cd /home/ubuntu/CLionProjects/CAdvanced-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/CLionProjects/CAdvanced-master /home/ubuntu/CLionProjects/CAdvanced-master/DebugPrintf /home/ubuntu/CLionProjects/CAdvanced-master/build /home/ubuntu/CLionProjects/CAdvanced-master/build/DebugPrintf /home/ubuntu/CLionProjects/CAdvanced-master/build/DebugPrintf/CMakeFiles/debug_printf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : DebugPrintf/CMakeFiles/debug_printf.dir/depend

