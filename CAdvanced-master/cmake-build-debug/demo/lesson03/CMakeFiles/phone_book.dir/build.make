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
include demo/lesson03/CMakeFiles/phone_book.dir/depend.make

# Include the progress variables for this target.
include demo/lesson03/CMakeFiles/phone_book.dir/progress.make

# Include the compile flags for this target's objects.
include demo/lesson03/CMakeFiles/phone_book.dir/flags.make

demo/lesson03/CMakeFiles/phone_book.dir/phone_book.c.o: demo/lesson03/CMakeFiles/phone_book.dir/flags.make
demo/lesson03/CMakeFiles/phone_book.dir/phone_book.c.o: ../demo/lesson03/phone_book.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object demo/lesson03/CMakeFiles/phone_book.dir/phone_book.c.o"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson03 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/phone_book.dir/phone_book.c.o   -c /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson03/phone_book.c

demo/lesson03/CMakeFiles/phone_book.dir/phone_book.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/phone_book.dir/phone_book.c.i"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson03 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson03/phone_book.c > CMakeFiles/phone_book.dir/phone_book.c.i

demo/lesson03/CMakeFiles/phone_book.dir/phone_book.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/phone_book.dir/phone_book.c.s"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson03 && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson03/phone_book.c -o CMakeFiles/phone_book.dir/phone_book.c.s

# Object files for target phone_book
phone_book_OBJECTS = \
"CMakeFiles/phone_book.dir/phone_book.c.o"

# External object files for target phone_book
phone_book_EXTERNAL_OBJECTS =

demo/lesson03/phone_book: demo/lesson03/CMakeFiles/phone_book.dir/phone_book.c.o
demo/lesson03/phone_book: demo/lesson03/CMakeFiles/phone_book.dir/build.make
demo/lesson03/phone_book: DebugPrintf/libdebug_printf.a
demo/lesson03/phone_book: demo/lesson03/CMakeFiles/phone_book.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable phone_book"
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson03 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/phone_book.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
demo/lesson03/CMakeFiles/phone_book.dir/build: demo/lesson03/phone_book

.PHONY : demo/lesson03/CMakeFiles/phone_book.dir/build

demo/lesson03/CMakeFiles/phone_book.dir/clean:
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson03 && $(CMAKE_COMMAND) -P CMakeFiles/phone_book.dir/cmake_clean.cmake
.PHONY : demo/lesson03/CMakeFiles/phone_book.dir/clean

demo/lesson03/CMakeFiles/phone_book.dir/depend:
	cd /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/CLionProjects/CAdvanced-master /home/ubuntu/CLionProjects/CAdvanced-master/demo/lesson03 /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson03 /home/ubuntu/CLionProjects/CAdvanced-master/cmake-build-debug/demo/lesson03/CMakeFiles/phone_book.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : demo/lesson03/CMakeFiles/phone_book.dir/depend
