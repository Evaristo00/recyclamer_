# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/ros/Escritorio/prueba/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ros/Escritorio/prueba/build

# Utility rule file for light_buoy_colors_msgs_autogen.

# Include the progress variables for this target.
include recyclamerunlp/vrx_gazebo/msgs/CMakeFiles/light_buoy_colors_msgs_autogen.dir/progress.make

recyclamerunlp/vrx_gazebo/msgs/CMakeFiles/light_buoy_colors_msgs_autogen: recyclamerunlp/vrx_gazebo/msgs/light_buoy_colors.pb.cc
recyclamerunlp/vrx_gazebo/msgs/CMakeFiles/light_buoy_colors_msgs_autogen: recyclamerunlp/vrx_gazebo/msgs/light_buoy_colors.pb.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ros/Escritorio/prueba/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target light_buoy_colors_msgs"
	cd /home/ros/Escritorio/prueba/build/recyclamerunlp/vrx_gazebo/msgs && /usr/bin/cmake -E cmake_autogen /home/ros/Escritorio/prueba/build/recyclamerunlp/vrx_gazebo/msgs/CMakeFiles/light_buoy_colors_msgs_autogen.dir/AutogenInfo.json ""

recyclamerunlp/vrx_gazebo/msgs/light_buoy_colors.pb.h: /home/ros/Escritorio/prueba/src/recyclamerunlp/vrx_gazebo/msgs/light_buoy_colors.proto
recyclamerunlp/vrx_gazebo/msgs/light_buoy_colors.pb.h: /usr/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ros/Escritorio/prueba/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Running cpp protocol buffer compiler on light_buoy_colors.proto"
	cd /home/ros/Escritorio/prueba/build/recyclamerunlp/vrx_gazebo/msgs && /usr/bin/protoc --cpp_out /home/ros/Escritorio/prueba/build/recyclamerunlp/vrx_gazebo/msgs -I /home/ros/Escritorio/prueba/src/recyclamerunlp/vrx_gazebo/msgs -I /usr/include/gazebo-11/gazebo/msgs/proto /home/ros/Escritorio/prueba/src/recyclamerunlp/vrx_gazebo/msgs/light_buoy_colors.proto

recyclamerunlp/vrx_gazebo/msgs/light_buoy_colors.pb.cc: recyclamerunlp/vrx_gazebo/msgs/light_buoy_colors.pb.h
	@$(CMAKE_COMMAND) -E touch_nocreate recyclamerunlp/vrx_gazebo/msgs/light_buoy_colors.pb.cc

light_buoy_colors_msgs_autogen: recyclamerunlp/vrx_gazebo/msgs/CMakeFiles/light_buoy_colors_msgs_autogen
light_buoy_colors_msgs_autogen: recyclamerunlp/vrx_gazebo/msgs/light_buoy_colors.pb.h
light_buoy_colors_msgs_autogen: recyclamerunlp/vrx_gazebo/msgs/light_buoy_colors.pb.cc
light_buoy_colors_msgs_autogen: recyclamerunlp/vrx_gazebo/msgs/CMakeFiles/light_buoy_colors_msgs_autogen.dir/build.make

.PHONY : light_buoy_colors_msgs_autogen

# Rule to build all files generated by this target.
recyclamerunlp/vrx_gazebo/msgs/CMakeFiles/light_buoy_colors_msgs_autogen.dir/build: light_buoy_colors_msgs_autogen

.PHONY : recyclamerunlp/vrx_gazebo/msgs/CMakeFiles/light_buoy_colors_msgs_autogen.dir/build

recyclamerunlp/vrx_gazebo/msgs/CMakeFiles/light_buoy_colors_msgs_autogen.dir/clean:
	cd /home/ros/Escritorio/prueba/build/recyclamerunlp/vrx_gazebo/msgs && $(CMAKE_COMMAND) -P CMakeFiles/light_buoy_colors_msgs_autogen.dir/cmake_clean.cmake
.PHONY : recyclamerunlp/vrx_gazebo/msgs/CMakeFiles/light_buoy_colors_msgs_autogen.dir/clean

recyclamerunlp/vrx_gazebo/msgs/CMakeFiles/light_buoy_colors_msgs_autogen.dir/depend:
	cd /home/ros/Escritorio/prueba/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ros/Escritorio/prueba/src /home/ros/Escritorio/prueba/src/recyclamerunlp/vrx_gazebo/msgs /home/ros/Escritorio/prueba/build /home/ros/Escritorio/prueba/build/recyclamerunlp/vrx_gazebo/msgs /home/ros/Escritorio/prueba/build/recyclamerunlp/vrx_gazebo/msgs/CMakeFiles/light_buoy_colors_msgs_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : recyclamerunlp/vrx_gazebo/msgs/CMakeFiles/light_buoy_colors_msgs_autogen.dir/depend
