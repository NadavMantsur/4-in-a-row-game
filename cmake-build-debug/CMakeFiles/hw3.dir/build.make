# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\zzz\Desktop\Nadav\234117\hw3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\zzz\Desktop\Nadav\234117\hw3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hw3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw3.dir/flags.make

CMakeFiles/hw3.dir/hw3q1.c.obj: CMakeFiles/hw3.dir/flags.make
CMakeFiles/hw3.dir/hw3q1.c.obj: ../hw3q1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zzz\Desktop\Nadav\234117\hw3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/hw3.dir/hw3q1.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\hw3.dir\hw3q1.c.obj   -c C:\Users\zzz\Desktop\Nadav\234117\hw3\hw3q1.c

CMakeFiles/hw3.dir/hw3q1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hw3.dir/hw3q1.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\zzz\Desktop\Nadav\234117\hw3\hw3q1.c > CMakeFiles\hw3.dir\hw3q1.c.i

CMakeFiles/hw3.dir/hw3q1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hw3.dir/hw3q1.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\zzz\Desktop\Nadav\234117\hw3\hw3q1.c -o CMakeFiles\hw3.dir\hw3q1.c.s

# Object files for target hw3
hw3_OBJECTS = \
"CMakeFiles/hw3.dir/hw3q1.c.obj"

# External object files for target hw3
hw3_EXTERNAL_OBJECTS =

hw3.exe: CMakeFiles/hw3.dir/hw3q1.c.obj
hw3.exe: CMakeFiles/hw3.dir/build.make
hw3.exe: CMakeFiles/hw3.dir/linklibs.rsp
hw3.exe: CMakeFiles/hw3.dir/objects1.rsp
hw3.exe: CMakeFiles/hw3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\zzz\Desktop\Nadav\234117\hw3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable hw3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hw3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw3.dir/build: hw3.exe

.PHONY : CMakeFiles/hw3.dir/build

CMakeFiles/hw3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hw3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/hw3.dir/clean

CMakeFiles/hw3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\zzz\Desktop\Nadav\234117\hw3 C:\Users\zzz\Desktop\Nadav\234117\hw3 C:\Users\zzz\Desktop\Nadav\234117\hw3\cmake-build-debug C:\Users\zzz\Desktop\Nadav\234117\hw3\cmake-build-debug C:\Users\zzz\Desktop\Nadav\234117\hw3\cmake-build-debug\CMakeFiles\hw3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw3.dir/depend

