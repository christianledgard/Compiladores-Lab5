# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/christianledgard/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/211.7442.42/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/christianledgard/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/211.7442.42/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/christianledgard/Documents/2021-I/Comp/Lab5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/christianledgard/Documents/2021-I/Comp/Lab5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab5.dir/flags.make

CMakeFiles/Lab5.dir/main.cpp.o: CMakeFiles/Lab5.dir/flags.make
CMakeFiles/Lab5.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christianledgard/Documents/2021-I/Comp/Lab5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab5.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab5.dir/main.cpp.o -c /Users/christianledgard/Documents/2021-I/Comp/Lab5/main.cpp

CMakeFiles/Lab5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab5.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christianledgard/Documents/2021-I/Comp/Lab5/main.cpp > CMakeFiles/Lab5.dir/main.cpp.i

CMakeFiles/Lab5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab5.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christianledgard/Documents/2021-I/Comp/Lab5/main.cpp -o CMakeFiles/Lab5.dir/main.cpp.s

# Object files for target Lab5
Lab5_OBJECTS = \
"CMakeFiles/Lab5.dir/main.cpp.o"

# External object files for target Lab5
Lab5_EXTERNAL_OBJECTS =

Lab5: CMakeFiles/Lab5.dir/main.cpp.o
Lab5: CMakeFiles/Lab5.dir/build.make
Lab5: CMakeFiles/Lab5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/christianledgard/Documents/2021-I/Comp/Lab5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab5.dir/build: Lab5

.PHONY : CMakeFiles/Lab5.dir/build

CMakeFiles/Lab5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab5.dir/clean

CMakeFiles/Lab5.dir/depend:
	cd /Users/christianledgard/Documents/2021-I/Comp/Lab5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/christianledgard/Documents/2021-I/Comp/Lab5 /Users/christianledgard/Documents/2021-I/Comp/Lab5 /Users/christianledgard/Documents/2021-I/Comp/Lab5/cmake-build-debug /Users/christianledgard/Documents/2021-I/Comp/Lab5/cmake-build-debug /Users/christianledgard/Documents/2021-I/Comp/Lab5/cmake-build-debug/CMakeFiles/Lab5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab5.dir/depend

