# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/franco/Downloads/clion-2019.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/franco/Downloads/clion-2019.2.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/franco/Documents/CLionProjects/algo2/labo4/ejercitacion_punteros

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/franco/Documents/CLionProjects/algo2/labo4/ejercitacion_punteros/cmake-build-debug

# Utility rule file for ej2_correrValgrind.

# Include the progress variables for this target.
include CMakeFiles/ej2_correrValgrind.dir/progress.make

CMakeFiles/ej2_correrValgrind: ej1
	valgrind --leak-check=full -v ./ej1 2>&1

ej2_correrValgrind: CMakeFiles/ej2_correrValgrind
ej2_correrValgrind: CMakeFiles/ej2_correrValgrind.dir/build.make

.PHONY : ej2_correrValgrind

# Rule to build all files generated by this target.
CMakeFiles/ej2_correrValgrind.dir/build: ej2_correrValgrind

.PHONY : CMakeFiles/ej2_correrValgrind.dir/build

CMakeFiles/ej2_correrValgrind.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej2_correrValgrind.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej2_correrValgrind.dir/clean

CMakeFiles/ej2_correrValgrind.dir/depend:
	cd /home/franco/Documents/CLionProjects/algo2/labo4/ejercitacion_punteros/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/franco/Documents/CLionProjects/algo2/labo4/ejercitacion_punteros /home/franco/Documents/CLionProjects/algo2/labo4/ejercitacion_punteros /home/franco/Documents/CLionProjects/algo2/labo4/ejercitacion_punteros/cmake-build-debug /home/franco/Documents/CLionProjects/algo2/labo4/ejercitacion_punteros/cmake-build-debug /home/franco/Documents/CLionProjects/algo2/labo4/ejercitacion_punteros/cmake-build-debug/CMakeFiles/ej2_correrValgrind.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ej2_correrValgrind.dir/depend

