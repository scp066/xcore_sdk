# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/allah/Documents/xcore_sdk/projects/snd_rcv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/allah/Documents/xcore_sdk/projects/snd_rcv/build

# Utility rule file for snd_rcv.xe.

# Include any custom commands dependencies for this target.
include CMakeFiles/snd_rcv.xe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/snd_rcv.xe.dir/progress.make

CMakeFiles/snd_rcv.xe: intermediates/0.xe
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/allah/Documents/xcore_sdk/projects/snd_rcv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Move tile binaries"
	mkdir -p /home/allah/Documents/xcore_sdk/projects/snd_rcv/bin
	cp /home/allah/Documents/xcore_sdk/projects/snd_rcv/build/intermediates/0.xe /home/allah/Documents/xcore_sdk/projects/snd_rcv/bin/snd_rcv.xe

snd_rcv.xe: CMakeFiles/snd_rcv.xe
snd_rcv.xe: CMakeFiles/snd_rcv.xe.dir/build.make
.PHONY : snd_rcv.xe

# Rule to build all files generated by this target.
CMakeFiles/snd_rcv.xe.dir/build: snd_rcv.xe
.PHONY : CMakeFiles/snd_rcv.xe.dir/build

CMakeFiles/snd_rcv.xe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/snd_rcv.xe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/snd_rcv.xe.dir/clean

CMakeFiles/snd_rcv.xe.dir/depend:
	cd /home/allah/Documents/xcore_sdk/projects/snd_rcv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/allah/Documents/xcore_sdk/projects/snd_rcv /home/allah/Documents/xcore_sdk/projects/snd_rcv /home/allah/Documents/xcore_sdk/projects/snd_rcv/build /home/allah/Documents/xcore_sdk/projects/snd_rcv/build /home/allah/Documents/xcore_sdk/projects/snd_rcv/build/CMakeFiles/snd_rcv.xe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/snd_rcv.xe.dir/depend

