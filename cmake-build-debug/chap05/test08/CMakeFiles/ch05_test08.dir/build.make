# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /home/bont/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/bont/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bont/CLionProjects/multi_threading

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bont/CLionProjects/multi_threading/cmake-build-debug

# Include any dependencies generated for this target.
include chap05/test08/CMakeFiles/ch05_test08.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include chap05/test08/CMakeFiles/ch05_test08.dir/compiler_depend.make

# Include the progress variables for this target.
include chap05/test08/CMakeFiles/ch05_test08.dir/progress.make

# Include the compile flags for this target's objects.
include chap05/test08/CMakeFiles/ch05_test08.dir/flags.make

chap05/test08/CMakeFiles/ch05_test08.dir/code1.cpp.o: chap05/test08/CMakeFiles/ch05_test08.dir/flags.make
chap05/test08/CMakeFiles/ch05_test08.dir/code1.cpp.o: /home/bont/CLionProjects/multi_threading/chap05/test08/code1.cpp
chap05/test08/CMakeFiles/ch05_test08.dir/code1.cpp.o: chap05/test08/CMakeFiles/ch05_test08.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/bont/CLionProjects/multi_threading/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object chap05/test08/CMakeFiles/ch05_test08.dir/code1.cpp.o"
	cd /home/bont/CLionProjects/multi_threading/cmake-build-debug/chap05/test08 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT chap05/test08/CMakeFiles/ch05_test08.dir/code1.cpp.o -MF CMakeFiles/ch05_test08.dir/code1.cpp.o.d -o CMakeFiles/ch05_test08.dir/code1.cpp.o -c /home/bont/CLionProjects/multi_threading/chap05/test08/code1.cpp

chap05/test08/CMakeFiles/ch05_test08.dir/code1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ch05_test08.dir/code1.cpp.i"
	cd /home/bont/CLionProjects/multi_threading/cmake-build-debug/chap05/test08 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bont/CLionProjects/multi_threading/chap05/test08/code1.cpp > CMakeFiles/ch05_test08.dir/code1.cpp.i

chap05/test08/CMakeFiles/ch05_test08.dir/code1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ch05_test08.dir/code1.cpp.s"
	cd /home/bont/CLionProjects/multi_threading/cmake-build-debug/chap05/test08 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bont/CLionProjects/multi_threading/chap05/test08/code1.cpp -o CMakeFiles/ch05_test08.dir/code1.cpp.s

# Object files for target ch05_test08
ch05_test08_OBJECTS = \
"CMakeFiles/ch05_test08.dir/code1.cpp.o"

# External object files for target ch05_test08
ch05_test08_EXTERNAL_OBJECTS =

chap05/test08/ch05_test08: chap05/test08/CMakeFiles/ch05_test08.dir/code1.cpp.o
chap05/test08/ch05_test08: chap05/test08/CMakeFiles/ch05_test08.dir/build.make
chap05/test08/ch05_test08: chap05/test08/CMakeFiles/ch05_test08.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/bont/CLionProjects/multi_threading/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ch05_test08"
	cd /home/bont/CLionProjects/multi_threading/cmake-build-debug/chap05/test08 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ch05_test08.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
chap05/test08/CMakeFiles/ch05_test08.dir/build: chap05/test08/ch05_test08
.PHONY : chap05/test08/CMakeFiles/ch05_test08.dir/build

chap05/test08/CMakeFiles/ch05_test08.dir/clean:
	cd /home/bont/CLionProjects/multi_threading/cmake-build-debug/chap05/test08 && $(CMAKE_COMMAND) -P CMakeFiles/ch05_test08.dir/cmake_clean.cmake
.PHONY : chap05/test08/CMakeFiles/ch05_test08.dir/clean

chap05/test08/CMakeFiles/ch05_test08.dir/depend:
	cd /home/bont/CLionProjects/multi_threading/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bont/CLionProjects/multi_threading /home/bont/CLionProjects/multi_threading/chap05/test08 /home/bont/CLionProjects/multi_threading/cmake-build-debug /home/bont/CLionProjects/multi_threading/cmake-build-debug/chap05/test08 /home/bont/CLionProjects/multi_threading/cmake-build-debug/chap05/test08/CMakeFiles/ch05_test08.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : chap05/test08/CMakeFiles/ch05_test08.dir/depend

