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
CMAKE_SOURCE_DIR = /home/lkf/Code/OpenCV/opencv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lkf/Code/OpenCV/opencv/build

# Include any dependencies generated for this target.
include CMakeFiles/watershed.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/watershed.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/watershed.dir/flags.make

CMakeFiles/watershed.dir/8.52.cpp.o: CMakeFiles/watershed.dir/flags.make
CMakeFiles/watershed.dir/8.52.cpp.o: ../8.52.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lkf/Code/OpenCV/opencv/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/watershed.dir/8.52.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/watershed.dir/8.52.cpp.o -c /home/lkf/Code/OpenCV/opencv/8.52.cpp

CMakeFiles/watershed.dir/8.52.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/watershed.dir/8.52.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lkf/Code/OpenCV/opencv/8.52.cpp > CMakeFiles/watershed.dir/8.52.cpp.i

CMakeFiles/watershed.dir/8.52.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/watershed.dir/8.52.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lkf/Code/OpenCV/opencv/8.52.cpp -o CMakeFiles/watershed.dir/8.52.cpp.s

CMakeFiles/watershed.dir/8.52.cpp.o.requires:
.PHONY : CMakeFiles/watershed.dir/8.52.cpp.o.requires

CMakeFiles/watershed.dir/8.52.cpp.o.provides: CMakeFiles/watershed.dir/8.52.cpp.o.requires
	$(MAKE) -f CMakeFiles/watershed.dir/build.make CMakeFiles/watershed.dir/8.52.cpp.o.provides.build
.PHONY : CMakeFiles/watershed.dir/8.52.cpp.o.provides

CMakeFiles/watershed.dir/8.52.cpp.o.provides.build: CMakeFiles/watershed.dir/8.52.cpp.o

# Object files for target watershed
watershed_OBJECTS = \
"CMakeFiles/watershed.dir/8.52.cpp.o"

# External object files for target watershed
watershed_EXTERNAL_OBJECTS =

watershed: CMakeFiles/watershed.dir/8.52.cpp.o
watershed: CMakeFiles/watershed.dir/build.make
watershed: /usr/local/lib/libopencv_viz.so.3.1.0
watershed: /usr/local/lib/libopencv_videostab.so.3.1.0
watershed: /usr/local/lib/libopencv_videoio.so.3.1.0
watershed: /usr/local/lib/libopencv_video.so.3.1.0
watershed: /usr/local/lib/libopencv_superres.so.3.1.0
watershed: /usr/local/lib/libopencv_stitching.so.3.1.0
watershed: /usr/local/lib/libopencv_shape.so.3.1.0
watershed: /usr/local/lib/libopencv_photo.so.3.1.0
watershed: /usr/local/lib/libopencv_objdetect.so.3.1.0
watershed: /usr/local/lib/libopencv_ml.so.3.1.0
watershed: /usr/local/lib/libopencv_imgproc.so.3.1.0
watershed: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
watershed: /usr/local/lib/libopencv_highgui.so.3.1.0
watershed: /usr/local/lib/libopencv_flann.so.3.1.0
watershed: /usr/local/lib/libopencv_features2d.so.3.1.0
watershed: /usr/local/lib/libopencv_core.so.3.1.0
watershed: /usr/local/lib/libopencv_calib3d.so.3.1.0
watershed: /usr/local/lib/libopencv_features2d.so.3.1.0
watershed: /usr/local/lib/libopencv_ml.so.3.1.0
watershed: /usr/local/lib/libopencv_highgui.so.3.1.0
watershed: /usr/local/lib/libopencv_videoio.so.3.1.0
watershed: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
watershed: /usr/local/lib/libopencv_flann.so.3.1.0
watershed: /usr/local/lib/libopencv_video.so.3.1.0
watershed: /usr/local/lib/libopencv_imgproc.so.3.1.0
watershed: /usr/local/lib/libopencv_core.so.3.1.0
watershed: CMakeFiles/watershed.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable watershed"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/watershed.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/watershed.dir/build: watershed
.PHONY : CMakeFiles/watershed.dir/build

CMakeFiles/watershed.dir/requires: CMakeFiles/watershed.dir/8.52.cpp.o.requires
.PHONY : CMakeFiles/watershed.dir/requires

CMakeFiles/watershed.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/watershed.dir/cmake_clean.cmake
.PHONY : CMakeFiles/watershed.dir/clean

CMakeFiles/watershed.dir/depend:
	cd /home/lkf/Code/OpenCV/opencv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lkf/Code/OpenCV/opencv /home/lkf/Code/OpenCV/opencv /home/lkf/Code/OpenCV/opencv/build /home/lkf/Code/OpenCV/opencv/build /home/lkf/Code/OpenCV/opencv/build/CMakeFiles/watershed.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/watershed.dir/depend

