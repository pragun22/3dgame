# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/pragun/pragun/sem4/graphics/Assignment2/3dgame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build

# Include any dependencies generated for this target.
include CMakeFiles/graphics_asgn1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/graphics_asgn1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graphics_asgn1.dir/flags.make

CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o: CMakeFiles/graphics_asgn1.dir/flags.make
CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o: ../src/ball.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o -c /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/ball.cpp

CMakeFiles/graphics_asgn1.dir/src/ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics_asgn1.dir/src/ball.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/ball.cpp > CMakeFiles/graphics_asgn1.dir/src/ball.cpp.i

CMakeFiles/graphics_asgn1.dir/src/ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics_asgn1.dir/src/ball.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/ball.cpp -o CMakeFiles/graphics_asgn1.dir/src/ball.cpp.s

CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o.requires:

.PHONY : CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o.requires

CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o.provides: CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o.provides.build
.PHONY : CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o.provides

CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o.provides.build: CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o


CMakeFiles/graphics_asgn1.dir/src/color.cpp.o: CMakeFiles/graphics_asgn1.dir/flags.make
CMakeFiles/graphics_asgn1.dir/src/color.cpp.o: ../src/color.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/graphics_asgn1.dir/src/color.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics_asgn1.dir/src/color.cpp.o -c /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/color.cpp

CMakeFiles/graphics_asgn1.dir/src/color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics_asgn1.dir/src/color.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/color.cpp > CMakeFiles/graphics_asgn1.dir/src/color.cpp.i

CMakeFiles/graphics_asgn1.dir/src/color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics_asgn1.dir/src/color.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/color.cpp -o CMakeFiles/graphics_asgn1.dir/src/color.cpp.s

CMakeFiles/graphics_asgn1.dir/src/color.cpp.o.requires:

.PHONY : CMakeFiles/graphics_asgn1.dir/src/color.cpp.o.requires

CMakeFiles/graphics_asgn1.dir/src/color.cpp.o.provides: CMakeFiles/graphics_asgn1.dir/src/color.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/color.cpp.o.provides.build
.PHONY : CMakeFiles/graphics_asgn1.dir/src/color.cpp.o.provides

CMakeFiles/graphics_asgn1.dir/src/color.cpp.o.provides.build: CMakeFiles/graphics_asgn1.dir/src/color.cpp.o


CMakeFiles/graphics_asgn1.dir/src/display.cpp.o: CMakeFiles/graphics_asgn1.dir/flags.make
CMakeFiles/graphics_asgn1.dir/src/display.cpp.o: ../src/display.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/graphics_asgn1.dir/src/display.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics_asgn1.dir/src/display.cpp.o -c /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/display.cpp

CMakeFiles/graphics_asgn1.dir/src/display.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics_asgn1.dir/src/display.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/display.cpp > CMakeFiles/graphics_asgn1.dir/src/display.cpp.i

CMakeFiles/graphics_asgn1.dir/src/display.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics_asgn1.dir/src/display.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/display.cpp -o CMakeFiles/graphics_asgn1.dir/src/display.cpp.s

CMakeFiles/graphics_asgn1.dir/src/display.cpp.o.requires:

.PHONY : CMakeFiles/graphics_asgn1.dir/src/display.cpp.o.requires

CMakeFiles/graphics_asgn1.dir/src/display.cpp.o.provides: CMakeFiles/graphics_asgn1.dir/src/display.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/display.cpp.o.provides.build
.PHONY : CMakeFiles/graphics_asgn1.dir/src/display.cpp.o.provides

CMakeFiles/graphics_asgn1.dir/src/display.cpp.o.provides.build: CMakeFiles/graphics_asgn1.dir/src/display.cpp.o


CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.o: CMakeFiles/graphics_asgn1.dir/flags.make
CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.o: ../src/enemies.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.o -c /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/enemies.cpp

CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/enemies.cpp > CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.i

CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/enemies.cpp -o CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.s

CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.o.requires:

.PHONY : CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.o.requires

CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.o.provides: CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.o.provides.build
.PHONY : CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.o.provides

CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.o.provides.build: CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.o


CMakeFiles/graphics_asgn1.dir/src/input.cpp.o: CMakeFiles/graphics_asgn1.dir/flags.make
CMakeFiles/graphics_asgn1.dir/src/input.cpp.o: ../src/input.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/graphics_asgn1.dir/src/input.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics_asgn1.dir/src/input.cpp.o -c /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/input.cpp

CMakeFiles/graphics_asgn1.dir/src/input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics_asgn1.dir/src/input.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/input.cpp > CMakeFiles/graphics_asgn1.dir/src/input.cpp.i

CMakeFiles/graphics_asgn1.dir/src/input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics_asgn1.dir/src/input.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/input.cpp -o CMakeFiles/graphics_asgn1.dir/src/input.cpp.s

CMakeFiles/graphics_asgn1.dir/src/input.cpp.o.requires:

.PHONY : CMakeFiles/graphics_asgn1.dir/src/input.cpp.o.requires

CMakeFiles/graphics_asgn1.dir/src/input.cpp.o.provides: CMakeFiles/graphics_asgn1.dir/src/input.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/input.cpp.o.provides.build
.PHONY : CMakeFiles/graphics_asgn1.dir/src/input.cpp.o.provides

CMakeFiles/graphics_asgn1.dir/src/input.cpp.o.provides.build: CMakeFiles/graphics_asgn1.dir/src/input.cpp.o


CMakeFiles/graphics_asgn1.dir/src/main.cpp.o: CMakeFiles/graphics_asgn1.dir/flags.make
CMakeFiles/graphics_asgn1.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/graphics_asgn1.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics_asgn1.dir/src/main.cpp.o -c /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/main.cpp

CMakeFiles/graphics_asgn1.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics_asgn1.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/main.cpp > CMakeFiles/graphics_asgn1.dir/src/main.cpp.i

CMakeFiles/graphics_asgn1.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics_asgn1.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/main.cpp -o CMakeFiles/graphics_asgn1.dir/src/main.cpp.s

CMakeFiles/graphics_asgn1.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/graphics_asgn1.dir/src/main.cpp.o.requires

CMakeFiles/graphics_asgn1.dir/src/main.cpp.o.provides: CMakeFiles/graphics_asgn1.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/graphics_asgn1.dir/src/main.cpp.o.provides

CMakeFiles/graphics_asgn1.dir/src/main.cpp.o.provides.build: CMakeFiles/graphics_asgn1.dir/src/main.cpp.o


CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o: CMakeFiles/graphics_asgn1.dir/flags.make
CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o: ../src/nonedit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o -c /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/nonedit.cpp

CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/nonedit.cpp > CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.i

CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/nonedit.cpp -o CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.s

CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o.requires:

.PHONY : CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o.requires

CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o.provides: CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o.provides.build
.PHONY : CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o.provides

CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o.provides.build: CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o


CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o: CMakeFiles/graphics_asgn1.dir/flags.make
CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o: ../src/other_handlers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o -c /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/other_handlers.cpp

CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/other_handlers.cpp > CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.i

CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/other_handlers.cpp -o CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.s

CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o.requires:

.PHONY : CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o.requires

CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o.provides: CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o.provides.build
.PHONY : CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o.provides

CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o.provides.build: CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o


CMakeFiles/graphics_asgn1.dir/src/plane.cpp.o: CMakeFiles/graphics_asgn1.dir/flags.make
CMakeFiles/graphics_asgn1.dir/src/plane.cpp.o: ../src/plane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/graphics_asgn1.dir/src/plane.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics_asgn1.dir/src/plane.cpp.o -c /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/plane.cpp

CMakeFiles/graphics_asgn1.dir/src/plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics_asgn1.dir/src/plane.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/plane.cpp > CMakeFiles/graphics_asgn1.dir/src/plane.cpp.i

CMakeFiles/graphics_asgn1.dir/src/plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics_asgn1.dir/src/plane.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/plane.cpp -o CMakeFiles/graphics_asgn1.dir/src/plane.cpp.s

CMakeFiles/graphics_asgn1.dir/src/plane.cpp.o.requires:

.PHONY : CMakeFiles/graphics_asgn1.dir/src/plane.cpp.o.requires

CMakeFiles/graphics_asgn1.dir/src/plane.cpp.o.provides: CMakeFiles/graphics_asgn1.dir/src/plane.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/plane.cpp.o.provides.build
.PHONY : CMakeFiles/graphics_asgn1.dir/src/plane.cpp.o.provides

CMakeFiles/graphics_asgn1.dir/src/plane.cpp.o.provides.build: CMakeFiles/graphics_asgn1.dir/src/plane.cpp.o


CMakeFiles/graphics_asgn1.dir/src/score.cpp.o: CMakeFiles/graphics_asgn1.dir/flags.make
CMakeFiles/graphics_asgn1.dir/src/score.cpp.o: ../src/score.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/graphics_asgn1.dir/src/score.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics_asgn1.dir/src/score.cpp.o -c /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/score.cpp

CMakeFiles/graphics_asgn1.dir/src/score.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics_asgn1.dir/src/score.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/score.cpp > CMakeFiles/graphics_asgn1.dir/src/score.cpp.i

CMakeFiles/graphics_asgn1.dir/src/score.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics_asgn1.dir/src/score.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/score.cpp -o CMakeFiles/graphics_asgn1.dir/src/score.cpp.s

CMakeFiles/graphics_asgn1.dir/src/score.cpp.o.requires:

.PHONY : CMakeFiles/graphics_asgn1.dir/src/score.cpp.o.requires

CMakeFiles/graphics_asgn1.dir/src/score.cpp.o.provides: CMakeFiles/graphics_asgn1.dir/src/score.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/score.cpp.o.provides.build
.PHONY : CMakeFiles/graphics_asgn1.dir/src/score.cpp.o.provides

CMakeFiles/graphics_asgn1.dir/src/score.cpp.o.provides.build: CMakeFiles/graphics_asgn1.dir/src/score.cpp.o


CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.o: CMakeFiles/graphics_asgn1.dir/flags.make
CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.o: ../src/terrain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.o -c /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/terrain.cpp

CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/terrain.cpp > CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.i

CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/terrain.cpp -o CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.s

CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.o.requires:

.PHONY : CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.o.requires

CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.o.provides: CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.o.provides.build
.PHONY : CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.o.provides

CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.o.provides.build: CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.o


CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o: CMakeFiles/graphics_asgn1.dir/flags.make
CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o: ../src/timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o -c /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/timer.cpp

CMakeFiles/graphics_asgn1.dir/src/timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics_asgn1.dir/src/timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/timer.cpp > CMakeFiles/graphics_asgn1.dir/src/timer.cpp.i

CMakeFiles/graphics_asgn1.dir/src/timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics_asgn1.dir/src/timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/src/timer.cpp -o CMakeFiles/graphics_asgn1.dir/src/timer.cpp.s

CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o.requires:

.PHONY : CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o.requires

CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o.provides: CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o.provides.build
.PHONY : CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o.provides

CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o.provides.build: CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o


# Object files for target graphics_asgn1
graphics_asgn1_OBJECTS = \
"CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o" \
"CMakeFiles/graphics_asgn1.dir/src/color.cpp.o" \
"CMakeFiles/graphics_asgn1.dir/src/display.cpp.o" \
"CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.o" \
"CMakeFiles/graphics_asgn1.dir/src/input.cpp.o" \
"CMakeFiles/graphics_asgn1.dir/src/main.cpp.o" \
"CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o" \
"CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o" \
"CMakeFiles/graphics_asgn1.dir/src/plane.cpp.o" \
"CMakeFiles/graphics_asgn1.dir/src/score.cpp.o" \
"CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.o" \
"CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o"

# External object files for target graphics_asgn1
graphics_asgn1_EXTERNAL_OBJECTS =

graphics_asgn1: CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o
graphics_asgn1: CMakeFiles/graphics_asgn1.dir/src/color.cpp.o
graphics_asgn1: CMakeFiles/graphics_asgn1.dir/src/display.cpp.o
graphics_asgn1: CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.o
graphics_asgn1: CMakeFiles/graphics_asgn1.dir/src/input.cpp.o
graphics_asgn1: CMakeFiles/graphics_asgn1.dir/src/main.cpp.o
graphics_asgn1: CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o
graphics_asgn1: CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o
graphics_asgn1: CMakeFiles/graphics_asgn1.dir/src/plane.cpp.o
graphics_asgn1: CMakeFiles/graphics_asgn1.dir/src/score.cpp.o
graphics_asgn1: CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.o
graphics_asgn1: CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o
graphics_asgn1: CMakeFiles/graphics_asgn1.dir/build.make
graphics_asgn1: CMakeFiles/graphics_asgn1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable graphics_asgn1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graphics_asgn1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graphics_asgn1.dir/build: graphics_asgn1

.PHONY : CMakeFiles/graphics_asgn1.dir/build

CMakeFiles/graphics_asgn1.dir/requires: CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o.requires
CMakeFiles/graphics_asgn1.dir/requires: CMakeFiles/graphics_asgn1.dir/src/color.cpp.o.requires
CMakeFiles/graphics_asgn1.dir/requires: CMakeFiles/graphics_asgn1.dir/src/display.cpp.o.requires
CMakeFiles/graphics_asgn1.dir/requires: CMakeFiles/graphics_asgn1.dir/src/enemies.cpp.o.requires
CMakeFiles/graphics_asgn1.dir/requires: CMakeFiles/graphics_asgn1.dir/src/input.cpp.o.requires
CMakeFiles/graphics_asgn1.dir/requires: CMakeFiles/graphics_asgn1.dir/src/main.cpp.o.requires
CMakeFiles/graphics_asgn1.dir/requires: CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o.requires
CMakeFiles/graphics_asgn1.dir/requires: CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o.requires
CMakeFiles/graphics_asgn1.dir/requires: CMakeFiles/graphics_asgn1.dir/src/plane.cpp.o.requires
CMakeFiles/graphics_asgn1.dir/requires: CMakeFiles/graphics_asgn1.dir/src/score.cpp.o.requires
CMakeFiles/graphics_asgn1.dir/requires: CMakeFiles/graphics_asgn1.dir/src/terrain.cpp.o.requires
CMakeFiles/graphics_asgn1.dir/requires: CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o.requires

.PHONY : CMakeFiles/graphics_asgn1.dir/requires

CMakeFiles/graphics_asgn1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graphics_asgn1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graphics_asgn1.dir/clean

CMakeFiles/graphics_asgn1.dir/depend:
	cd /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pragun/pragun/sem4/graphics/Assignment2/3dgame /home/pragun/pragun/sem4/graphics/Assignment2/3dgame /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build /home/pragun/pragun/sem4/graphics/Assignment2/3dgame/build/CMakeFiles/graphics_asgn1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/graphics_asgn1.dir/depend

