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
CMAKE_SOURCE_DIR = /home/deulee/project_dp/dummy_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/deulee/project_dp/dummy_test/build

# Utility rule file for clean-objs.

# Include any custom commands dependencies for this target.
include CMakeFiles/clean-objs.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/clean-objs.dir/progress.make

CMakeFiles/clean-objs:
	/usr/bin/cmake -E echo Removing\ object\ files\ in\ all\ subdirectories...
	find /home/deulee/project_dp/dummy_test/build/CMakeFiles -type f -name '*.o' -exec rm {} +
	/usr/bin/cmake -E echo Object\ files\ removed.

clean-objs: CMakeFiles/clean-objs
clean-objs: CMakeFiles/clean-objs.dir/build.make
.PHONY : clean-objs

# Rule to build all files generated by this target.
CMakeFiles/clean-objs.dir/build: clean-objs
.PHONY : CMakeFiles/clean-objs.dir/build

CMakeFiles/clean-objs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clean-objs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clean-objs.dir/clean

CMakeFiles/clean-objs.dir/depend:
	cd /home/deulee/project_dp/dummy_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/deulee/project_dp/dummy_test /home/deulee/project_dp/dummy_test /home/deulee/project_dp/dummy_test/build /home/deulee/project_dp/dummy_test/build /home/deulee/project_dp/dummy_test/build/CMakeFiles/clean-objs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/clean-objs.dir/depend

