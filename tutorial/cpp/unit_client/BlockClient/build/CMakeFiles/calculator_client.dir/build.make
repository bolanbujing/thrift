# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/build

# Include any dependencies generated for this target.
include CMakeFiles/calculator_client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/calculator_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/calculator_client.dir/flags.make

CMakeFiles/calculator_client.dir/main.cpp.o: CMakeFiles/calculator_client.dir/flags.make
CMakeFiles/calculator_client.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/calculator_client.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/calculator_client.dir/main.cpp.o -c /home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/main.cpp

CMakeFiles/calculator_client.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calculator_client.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/main.cpp > CMakeFiles/calculator_client.dir/main.cpp.i

CMakeFiles/calculator_client.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calculator_client.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/main.cpp -o CMakeFiles/calculator_client.dir/main.cpp.s

CMakeFiles/calculator_client.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/calculator_client.dir/main.cpp.o.requires

CMakeFiles/calculator_client.dir/main.cpp.o.provides: CMakeFiles/calculator_client.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/calculator_client.dir/build.make CMakeFiles/calculator_client.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/calculator_client.dir/main.cpp.o.provides

CMakeFiles/calculator_client.dir/main.cpp.o.provides.build: CMakeFiles/calculator_client.dir/main.cpp.o


CMakeFiles/calculator_client.dir/TBufferTransports.cpp.o: CMakeFiles/calculator_client.dir/flags.make
CMakeFiles/calculator_client.dir/TBufferTransports.cpp.o: ../TBufferTransports.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/calculator_client.dir/TBufferTransports.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/calculator_client.dir/TBufferTransports.cpp.o -c /home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/TBufferTransports.cpp

CMakeFiles/calculator_client.dir/TBufferTransports.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calculator_client.dir/TBufferTransports.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/TBufferTransports.cpp > CMakeFiles/calculator_client.dir/TBufferTransports.cpp.i

CMakeFiles/calculator_client.dir/TBufferTransports.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calculator_client.dir/TBufferTransports.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/TBufferTransports.cpp -o CMakeFiles/calculator_client.dir/TBufferTransports.cpp.s

CMakeFiles/calculator_client.dir/TBufferTransports.cpp.o.requires:

.PHONY : CMakeFiles/calculator_client.dir/TBufferTransports.cpp.o.requires

CMakeFiles/calculator_client.dir/TBufferTransports.cpp.o.provides: CMakeFiles/calculator_client.dir/TBufferTransports.cpp.o.requires
	$(MAKE) -f CMakeFiles/calculator_client.dir/build.make CMakeFiles/calculator_client.dir/TBufferTransports.cpp.o.provides.build
.PHONY : CMakeFiles/calculator_client.dir/TBufferTransports.cpp.o.provides

CMakeFiles/calculator_client.dir/TBufferTransports.cpp.o.provides.build: CMakeFiles/calculator_client.dir/TBufferTransports.cpp.o


CMakeFiles/calculator_client.dir/Calculator.cpp.o: CMakeFiles/calculator_client.dir/flags.make
CMakeFiles/calculator_client.dir/Calculator.cpp.o: ../Calculator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/calculator_client.dir/Calculator.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/calculator_client.dir/Calculator.cpp.o -c /home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/Calculator.cpp

CMakeFiles/calculator_client.dir/Calculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calculator_client.dir/Calculator.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/Calculator.cpp > CMakeFiles/calculator_client.dir/Calculator.cpp.i

CMakeFiles/calculator_client.dir/Calculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calculator_client.dir/Calculator.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/Calculator.cpp -o CMakeFiles/calculator_client.dir/Calculator.cpp.s

CMakeFiles/calculator_client.dir/Calculator.cpp.o.requires:

.PHONY : CMakeFiles/calculator_client.dir/Calculator.cpp.o.requires

CMakeFiles/calculator_client.dir/Calculator.cpp.o.provides: CMakeFiles/calculator_client.dir/Calculator.cpp.o.requires
	$(MAKE) -f CMakeFiles/calculator_client.dir/build.make CMakeFiles/calculator_client.dir/Calculator.cpp.o.provides.build
.PHONY : CMakeFiles/calculator_client.dir/Calculator.cpp.o.provides

CMakeFiles/calculator_client.dir/Calculator.cpp.o.provides.build: CMakeFiles/calculator_client.dir/Calculator.cpp.o


# Object files for target calculator_client
calculator_client_OBJECTS = \
"CMakeFiles/calculator_client.dir/main.cpp.o" \
"CMakeFiles/calculator_client.dir/TBufferTransports.cpp.o" \
"CMakeFiles/calculator_client.dir/Calculator.cpp.o"

# External object files for target calculator_client
calculator_client_EXTERNAL_OBJECTS =

calculator_client: CMakeFiles/calculator_client.dir/main.cpp.o
calculator_client: CMakeFiles/calculator_client.dir/TBufferTransports.cpp.o
calculator_client: CMakeFiles/calculator_client.dir/Calculator.cpp.o
calculator_client: CMakeFiles/calculator_client.dir/build.make
calculator_client: CMakeFiles/calculator_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable calculator_client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/calculator_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/calculator_client.dir/build: calculator_client

.PHONY : CMakeFiles/calculator_client.dir/build

CMakeFiles/calculator_client.dir/requires: CMakeFiles/calculator_client.dir/main.cpp.o.requires
CMakeFiles/calculator_client.dir/requires: CMakeFiles/calculator_client.dir/TBufferTransports.cpp.o.requires
CMakeFiles/calculator_client.dir/requires: CMakeFiles/calculator_client.dir/Calculator.cpp.o.requires

.PHONY : CMakeFiles/calculator_client.dir/requires

CMakeFiles/calculator_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/calculator_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/calculator_client.dir/clean

CMakeFiles/calculator_client.dir/depend:
	cd /home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient /home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient /home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/build /home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/build /home/xiaobo/cpp/thrift-master/tutorial/cpp/unit_client/BlockClient/build/CMakeFiles/calculator_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/calculator_client.dir/depend

