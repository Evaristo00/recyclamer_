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
CMAKE_SOURCE_DIR = /home/rc/recyclamer_/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rc/recyclamer_/build

# Utility rule file for scoring_plugin_automoc.

# Include the progress variables for this target.
include recyclamerunlp/vrx_gazebo/CMakeFiles/scoring_plugin_automoc.dir/progress.make

recyclamerunlp/vrx_gazebo/CMakeFiles/scoring_plugin_automoc:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/rc/recyclamer_/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic moc and uic for target scoring_plugin"
	cd /home/rc/recyclamer_/build/recyclamerunlp/vrx_gazebo && /usr/bin/cmake -E cmake_autogen /home/rc/recyclamer_/build/recyclamerunlp/vrx_gazebo/CMakeFiles/scoring_plugin_automoc.dir/ ""

scoring_plugin_automoc: recyclamerunlp/vrx_gazebo/CMakeFiles/scoring_plugin_automoc
scoring_plugin_automoc: recyclamerunlp/vrx_gazebo/CMakeFiles/scoring_plugin_automoc.dir/build.make

.PHONY : scoring_plugin_automoc

# Rule to build all files generated by this target.
recyclamerunlp/vrx_gazebo/CMakeFiles/scoring_plugin_automoc.dir/build: scoring_plugin_automoc

.PHONY : recyclamerunlp/vrx_gazebo/CMakeFiles/scoring_plugin_automoc.dir/build

recyclamerunlp/vrx_gazebo/CMakeFiles/scoring_plugin_automoc.dir/clean:
	cd /home/rc/recyclamer_/build/recyclamerunlp/vrx_gazebo && $(CMAKE_COMMAND) -P CMakeFiles/scoring_plugin_automoc.dir/cmake_clean.cmake
.PHONY : recyclamerunlp/vrx_gazebo/CMakeFiles/scoring_plugin_automoc.dir/clean

recyclamerunlp/vrx_gazebo/CMakeFiles/scoring_plugin_automoc.dir/depend:
	cd /home/rc/recyclamer_/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rc/recyclamer_/src /home/rc/recyclamer_/src/recyclamerunlp/vrx_gazebo /home/rc/recyclamer_/build /home/rc/recyclamer_/build/recyclamerunlp/vrx_gazebo /home/rc/recyclamer_/build/recyclamerunlp/vrx_gazebo/CMakeFiles/scoring_plugin_automoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : recyclamerunlp/vrx_gazebo/CMakeFiles/scoring_plugin_automoc.dir/depend

