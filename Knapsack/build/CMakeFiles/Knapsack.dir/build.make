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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.17.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.17.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/okamoto/Desktop/Opt/Knapsack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/okamoto/Desktop/Opt/Knapsack/build

# Include any dependencies generated for this target.
include CMakeFiles/Knapsack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Knapsack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Knapsack.dir/flags.make

CMakeFiles/Knapsack.dir/Knapsack.cpp.o: CMakeFiles/Knapsack.dir/flags.make
CMakeFiles/Knapsack.dir/Knapsack.cpp.o: ../Knapsack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/okamoto/Desktop/Opt/Knapsack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Knapsack.dir/Knapsack.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Knapsack.dir/Knapsack.cpp.o -c /Users/okamoto/Desktop/Opt/Knapsack/Knapsack.cpp

CMakeFiles/Knapsack.dir/Knapsack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Knapsack.dir/Knapsack.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/okamoto/Desktop/Opt/Knapsack/Knapsack.cpp > CMakeFiles/Knapsack.dir/Knapsack.cpp.i

CMakeFiles/Knapsack.dir/Knapsack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Knapsack.dir/Knapsack.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/okamoto/Desktop/Opt/Knapsack/Knapsack.cpp -o CMakeFiles/Knapsack.dir/Knapsack.cpp.s

# Object files for target Knapsack
Knapsack_OBJECTS = \
"CMakeFiles/Knapsack.dir/Knapsack.cpp.o"

# External object files for target Knapsack
Knapsack_EXTERNAL_OBJECTS =

Knapsack.cpython-37m-darwin.so: CMakeFiles/Knapsack.dir/Knapsack.cpp.o
Knapsack.cpython-37m-darwin.so: CMakeFiles/Knapsack.dir/build.make
Knapsack.cpython-37m-darwin.so: CMakeFiles/Knapsack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/okamoto/Desktop/Opt/Knapsack/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library Knapsack.cpython-37m-darwin.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Knapsack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Knapsack.dir/build: Knapsack.cpython-37m-darwin.so

.PHONY : CMakeFiles/Knapsack.dir/build

CMakeFiles/Knapsack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Knapsack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Knapsack.dir/clean

CMakeFiles/Knapsack.dir/depend:
	cd /Users/okamoto/Desktop/Opt/Knapsack/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/okamoto/Desktop/Opt/Knapsack /Users/okamoto/Desktop/Opt/Knapsack /Users/okamoto/Desktop/Opt/Knapsack/build /Users/okamoto/Desktop/Opt/Knapsack/build /Users/okamoto/Desktop/Opt/Knapsack/build/CMakeFiles/Knapsack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Knapsack.dir/depend

