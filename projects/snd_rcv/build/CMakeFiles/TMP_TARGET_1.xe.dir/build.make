# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_SOURCE_DIR = /home/soydev/XMOS/xcore_sdk/projects/snd_rcv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/soydev/XMOS/xcore_sdk/projects/snd_rcv/build

# Utility rule file for TMP_TARGET_1.xe.

# Include any custom commands dependencies for this target.
include CMakeFiles/TMP_TARGET_1.xe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TMP_TARGET_1.xe.dir/progress.make

CMakeFiles/TMP_TARGET_1.xe: intermediates/1.xe
CMakeFiles/TMP_TARGET_1.xe: intermediates/0.xe
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/soydev/XMOS/xcore_sdk/projects/snd_rcv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Merging tile 1 into 0.xe"
	mkdir -p /home/soydev/XMOS/xcore_sdk/projects/snd_rcv/build/intermediates/1
	xobjdump --split --split-dir /home/soydev/XMOS/xcore_sdk/projects/snd_rcv/build/intermediates/1 /home/soydev/XMOS/xcore_sdk/projects/snd_rcv/build/intermediates/1.xe
	xobjdump /home/soydev/XMOS/xcore_sdk/projects/snd_rcv/build/intermediates/0.xe -r 0,1,/home/soydev/XMOS/xcore_sdk/projects/snd_rcv/build/intermediates/1/image_n0c1_2.elf

TMP_TARGET_1.xe: CMakeFiles/TMP_TARGET_1.xe
TMP_TARGET_1.xe: CMakeFiles/TMP_TARGET_1.xe.dir/build.make
.PHONY : TMP_TARGET_1.xe

# Rule to build all files generated by this target.
CMakeFiles/TMP_TARGET_1.xe.dir/build: TMP_TARGET_1.xe
.PHONY : CMakeFiles/TMP_TARGET_1.xe.dir/build

CMakeFiles/TMP_TARGET_1.xe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TMP_TARGET_1.xe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TMP_TARGET_1.xe.dir/clean

CMakeFiles/TMP_TARGET_1.xe.dir/depend:
	cd /home/soydev/XMOS/xcore_sdk/projects/snd_rcv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/soydev/XMOS/xcore_sdk/projects/snd_rcv /home/soydev/XMOS/xcore_sdk/projects/snd_rcv /home/soydev/XMOS/xcore_sdk/projects/snd_rcv/build /home/soydev/XMOS/xcore_sdk/projects/snd_rcv/build /home/soydev/XMOS/xcore_sdk/projects/snd_rcv/build/CMakeFiles/TMP_TARGET_1.xe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TMP_TARGET_1.xe.dir/depend

