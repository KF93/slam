# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/lkf/Code/Pi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lkf/Code/Pi/build

# Include any dependencies generated for this target.
include CMakeFiles/monitor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/monitor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/monitor.dir/flags.make

CMakeFiles/monitor.dir/monitor.cpp.o: CMakeFiles/monitor.dir/flags.make
CMakeFiles/monitor.dir/monitor.cpp.o: ../monitor.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lkf/Code/Pi/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/monitor.dir/monitor.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/monitor.dir/monitor.cpp.o -c /home/lkf/Code/Pi/monitor.cpp

CMakeFiles/monitor.dir/monitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/monitor.dir/monitor.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lkf/Code/Pi/monitor.cpp > CMakeFiles/monitor.dir/monitor.cpp.i

CMakeFiles/monitor.dir/monitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/monitor.dir/monitor.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lkf/Code/Pi/monitor.cpp -o CMakeFiles/monitor.dir/monitor.cpp.s

CMakeFiles/monitor.dir/monitor.cpp.o.requires:
.PHONY : CMakeFiles/monitor.dir/monitor.cpp.o.requires

CMakeFiles/monitor.dir/monitor.cpp.o.provides: CMakeFiles/monitor.dir/monitor.cpp.o.requires
	$(MAKE) -f CMakeFiles/monitor.dir/build.make CMakeFiles/monitor.dir/monitor.cpp.o.provides.build
.PHONY : CMakeFiles/monitor.dir/monitor.cpp.o.provides

CMakeFiles/monitor.dir/monitor.cpp.o.provides.build: CMakeFiles/monitor.dir/monitor.cpp.o

# Object files for target monitor
monitor_OBJECTS = \
"CMakeFiles/monitor.dir/monitor.cpp.o"

# External object files for target monitor
monitor_EXTERNAL_OBJECTS =

monitor: CMakeFiles/monitor.dir/monitor.cpp.o
monitor: CMakeFiles/monitor.dir/build.make
monitor: /usr/local/lib/libopencv_viz.so.3.1.0
monitor: /usr/local/lib/libopencv_videostab.so.3.1.0
monitor: /usr/local/lib/libopencv_videoio.so.3.1.0
monitor: /usr/local/lib/libopencv_video.so.3.1.0
monitor: /usr/local/lib/libopencv_superres.so.3.1.0
monitor: /usr/local/lib/libopencv_stitching.so.3.1.0
monitor: /usr/local/lib/libopencv_shape.so.3.1.0
monitor: /usr/local/lib/libopencv_photo.so.3.1.0
monitor: /usr/local/lib/libopencv_objdetect.so.3.1.0
monitor: /usr/local/lib/libopencv_ml.so.3.1.0
monitor: /usr/local/lib/libopencv_imgproc.so.3.1.0
monitor: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
monitor: /usr/local/lib/libopencv_highgui.so.3.1.0
monitor: /usr/local/lib/libopencv_flann.so.3.1.0
monitor: /usr/local/lib/libopencv_features2d.so.3.1.0
monitor: /usr/local/lib/libopencv_core.so.3.1.0
monitor: /usr/local/lib/libopencv_calib3d.so.3.1.0
monitor: /usr/local/lib/libopencv_features2d.so.3.1.0
monitor: /usr/local/lib/libopencv_ml.so.3.1.0
monitor: /usr/local/lib/libopencv_highgui.so.3.1.0
monitor: /usr/local/lib/libopencv_videoio.so.3.1.0
monitor: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
monitor: /usr/local/lib/libopencv_flann.so.3.1.0
monitor: /usr/local/lib/libopencv_video.so.3.1.0
monitor: /usr/local/lib/libopencv_imgproc.so.3.1.0
monitor: /usr/local/lib/libopencv_core.so.3.1.0
monitor: CMakeFiles/monitor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable monitor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/monitor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/monitor.dir/build: monitor
.PHONY : CMakeFiles/monitor.dir/build

CMakeFiles/monitor.dir/requires: CMakeFiles/monitor.dir/monitor.cpp.o.requires
.PHONY : CMakeFiles/monitor.dir/requires

CMakeFiles/monitor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/monitor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/monitor.dir/clean

CMakeFiles/monitor.dir/depend:
	cd /home/lkf/Code/Pi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lkf/Code/Pi /home/lkf/Code/Pi /home/lkf/Code/Pi/build /home/lkf/Code/Pi/build /home/lkf/Code/Pi/build/CMakeFiles/monitor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/monitor.dir/depend

