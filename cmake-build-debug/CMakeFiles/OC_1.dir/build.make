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
CMAKE_COMMAND = /home/naxa1ka/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/213.6777.58/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/naxa1ka/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/213.6777.58/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/naxa1ka/Загрузки/OC_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/naxa1ka/Загрузки/OC_1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OC_1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OC_1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OC_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OC_1.dir/flags.make

CMakeFiles/OC_1.dir/main.c.o: CMakeFiles/OC_1.dir/flags.make
CMakeFiles/OC_1.dir/main.c.o: ../main.c
CMakeFiles/OC_1.dir/main.c.o: CMakeFiles/OC_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/naxa1ka/Загрузки/OC_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/OC_1.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/OC_1.dir/main.c.o -MF CMakeFiles/OC_1.dir/main.c.o.d -o CMakeFiles/OC_1.dir/main.c.o -c /home/naxa1ka/Загрузки/OC_1/main.c

CMakeFiles/OC_1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OC_1.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/naxa1ka/Загрузки/OC_1/main.c > CMakeFiles/OC_1.dir/main.c.i

CMakeFiles/OC_1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OC_1.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/naxa1ka/Загрузки/OC_1/main.c -o CMakeFiles/OC_1.dir/main.c.s

CMakeFiles/OC_1.dir/tar.c.o: CMakeFiles/OC_1.dir/flags.make
CMakeFiles/OC_1.dir/tar.c.o: ../tar.c
CMakeFiles/OC_1.dir/tar.c.o: CMakeFiles/OC_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/naxa1ka/Загрузки/OC_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/OC_1.dir/tar.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/OC_1.dir/tar.c.o -MF CMakeFiles/OC_1.dir/tar.c.o.d -o CMakeFiles/OC_1.dir/tar.c.o -c /home/naxa1ka/Загрузки/OC_1/tar.c

CMakeFiles/OC_1.dir/tar.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OC_1.dir/tar.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/naxa1ka/Загрузки/OC_1/tar.c > CMakeFiles/OC_1.dir/tar.c.i

CMakeFiles/OC_1.dir/tar.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OC_1.dir/tar.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/naxa1ka/Загрузки/OC_1/tar.c -o CMakeFiles/OC_1.dir/tar.c.s

# Object files for target OC_1
OC_1_OBJECTS = \
"CMakeFiles/OC_1.dir/main.c.o" \
"CMakeFiles/OC_1.dir/tar.c.o"

# External object files for target OC_1
OC_1_EXTERNAL_OBJECTS =

OC_1: CMakeFiles/OC_1.dir/main.c.o
OC_1: CMakeFiles/OC_1.dir/tar.c.o
OC_1: CMakeFiles/OC_1.dir/build.make
OC_1: CMakeFiles/OC_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/naxa1ka/Загрузки/OC_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable OC_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OC_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OC_1.dir/build: OC_1
.PHONY : CMakeFiles/OC_1.dir/build

CMakeFiles/OC_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OC_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OC_1.dir/clean

CMakeFiles/OC_1.dir/depend:
	cd /home/naxa1ka/Загрузки/OC_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/naxa1ka/Загрузки/OC_1 /home/naxa1ka/Загрузки/OC_1 /home/naxa1ka/Загрузки/OC_1/cmake-build-debug /home/naxa1ka/Загрузки/OC_1/cmake-build-debug /home/naxa1ka/Загрузки/OC_1/cmake-build-debug/CMakeFiles/OC_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OC_1.dir/depend
