# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/maus/clion-2017.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/maus/clion-2017.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/maus/CLionProjects/eques

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maus/CLionProjects/eques/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/eques.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/eques.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/eques.dir/flags.make

CMakeFiles/eques.dir/main.cpp.o: CMakeFiles/eques.dir/flags.make
CMakeFiles/eques.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maus/CLionProjects/eques/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/eques.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/eques.dir/main.cpp.o -c /home/maus/CLionProjects/eques/main.cpp

CMakeFiles/eques.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/eques.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maus/CLionProjects/eques/main.cpp > CMakeFiles/eques.dir/main.cpp.i

CMakeFiles/eques.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/eques.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maus/CLionProjects/eques/main.cpp -o CMakeFiles/eques.dir/main.cpp.s

CMakeFiles/eques.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/eques.dir/main.cpp.o.requires

CMakeFiles/eques.dir/main.cpp.o.provides: CMakeFiles/eques.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/eques.dir/build.make CMakeFiles/eques.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/eques.dir/main.cpp.o.provides

CMakeFiles/eques.dir/main.cpp.o.provides.build: CMakeFiles/eques.dir/main.cpp.o


# Object files for target eques
eques_OBJECTS = \
"CMakeFiles/eques.dir/main.cpp.o"

# External object files for target eques
eques_EXTERNAL_OBJECTS =

eques: CMakeFiles/eques.dir/main.cpp.o
eques: CMakeFiles/eques.dir/build.make
eques: CMakeFiles/eques.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maus/CLionProjects/eques/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable eques"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/eques.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/eques.dir/build: eques

.PHONY : CMakeFiles/eques.dir/build

CMakeFiles/eques.dir/requires: CMakeFiles/eques.dir/main.cpp.o.requires

.PHONY : CMakeFiles/eques.dir/requires

CMakeFiles/eques.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/eques.dir/cmake_clean.cmake
.PHONY : CMakeFiles/eques.dir/clean

CMakeFiles/eques.dir/depend:
	cd /home/maus/CLionProjects/eques/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maus/CLionProjects/eques /home/maus/CLionProjects/eques /home/maus/CLionProjects/eques/cmake-build-debug /home/maus/CLionProjects/eques/cmake-build-debug /home/maus/CLionProjects/eques/cmake-build-debug/CMakeFiles/eques.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/eques.dir/depend
