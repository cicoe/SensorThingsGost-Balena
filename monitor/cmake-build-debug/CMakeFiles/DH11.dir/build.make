# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /snap/clion/61/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/61/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DH11.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DH11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DH11.dir/flags.make

CMakeFiles/DH11.dir/bbb_dht_read.c.o: CMakeFiles/DH11.dir/flags.make
CMakeFiles/DH11.dir/bbb_dht_read.c.o: ../bbb_dht_read.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DH11.dir/bbb_dht_read.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/DH11.dir/bbb_dht_read.c.o   -c /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/bbb_dht_read.c

CMakeFiles/DH11.dir/bbb_dht_read.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DH11.dir/bbb_dht_read.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/bbb_dht_read.c > CMakeFiles/DH11.dir/bbb_dht_read.c.i

CMakeFiles/DH11.dir/bbb_dht_read.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DH11.dir/bbb_dht_read.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/bbb_dht_read.c -o CMakeFiles/DH11.dir/bbb_dht_read.c.s

CMakeFiles/DH11.dir/bbb_mmio.c.o: CMakeFiles/DH11.dir/flags.make
CMakeFiles/DH11.dir/bbb_mmio.c.o: ../bbb_mmio.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/DH11.dir/bbb_mmio.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/DH11.dir/bbb_mmio.c.o   -c /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/bbb_mmio.c

CMakeFiles/DH11.dir/bbb_mmio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DH11.dir/bbb_mmio.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/bbb_mmio.c > CMakeFiles/DH11.dir/bbb_mmio.c.i

CMakeFiles/DH11.dir/bbb_mmio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DH11.dir/bbb_mmio.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/bbb_mmio.c -o CMakeFiles/DH11.dir/bbb_mmio.c.s

CMakeFiles/DH11.dir/common_dht_read.c.o: CMakeFiles/DH11.dir/flags.make
CMakeFiles/DH11.dir/common_dht_read.c.o: ../common_dht_read.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/DH11.dir/common_dht_read.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/DH11.dir/common_dht_read.c.o   -c /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/common_dht_read.c

CMakeFiles/DH11.dir/common_dht_read.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DH11.dir/common_dht_read.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/common_dht_read.c > CMakeFiles/DH11.dir/common_dht_read.c.i

CMakeFiles/DH11.dir/common_dht_read.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DH11.dir/common_dht_read.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/common_dht_read.c -o CMakeFiles/DH11.dir/common_dht_read.c.s

CMakeFiles/DH11.dir/main.c.o: CMakeFiles/DH11.dir/flags.make
CMakeFiles/DH11.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/DH11.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/DH11.dir/main.c.o   -c /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/main.c

CMakeFiles/DH11.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DH11.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/main.c > CMakeFiles/DH11.dir/main.c.i

CMakeFiles/DH11.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DH11.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/main.c -o CMakeFiles/DH11.dir/main.c.s

# Object files for target DH11
DH11_OBJECTS = \
"CMakeFiles/DH11.dir/bbb_dht_read.c.o" \
"CMakeFiles/DH11.dir/bbb_mmio.c.o" \
"CMakeFiles/DH11.dir/common_dht_read.c.o" \
"CMakeFiles/DH11.dir/main.c.o"

# External object files for target DH11
DH11_EXTERNAL_OBJECTS =

DH11: CMakeFiles/DH11.dir/bbb_dht_read.c.o
DH11: CMakeFiles/DH11.dir/bbb_mmio.c.o
DH11: CMakeFiles/DH11.dir/common_dht_read.c.o
DH11: CMakeFiles/DH11.dir/main.c.o
DH11: CMakeFiles/DH11.dir/build.make
DH11: CMakeFiles/DH11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable DH11"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DH11.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DH11.dir/build: DH11

.PHONY : CMakeFiles/DH11.dir/build

CMakeFiles/DH11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DH11.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DH11.dir/clean

CMakeFiles/DH11.dir/depend:
	cd /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11 /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11 /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/cmake-build-debug /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/cmake-build-debug /home/jwyngaard/Work/NEON_CiCoE18/ST_Beagle/app/DH11/cmake-build-debug/CMakeFiles/DH11.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DH11.dir/depend
