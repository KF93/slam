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
include CMakeFiles/warpAffine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/warpAffine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/warpAffine.dir/flags.make

CMakeFiles/warpAffine.dir/7.45.cpp.o: CMakeFiles/warpAffine.dir/flags.make
CMakeFiles/warpAffine.dir/7.45.cpp.o: ../7.45.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lkf/Code/OpenCV/opencv/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/warpAffine.dir/7.45.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/warpAffine.dir/7.45.cpp.o -c /home/lkf/Code/OpenCV/opencv/7.45.cpp

CMakeFiles/warpAffine.dir/7.45.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warpAffine.dir/7.45.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lkf/Code/OpenCV/opencv/7.45.cpp > CMakeFiles/warpAffine.dir/7.45.cpp.i

CMakeFiles/warpAffine.dir/7.45.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warpAffine.dir/7.45.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lkf/Code/OpenCV/opencv/7.45.cpp -o CMakeFiles/warpAffine.dir/7.45.cpp.s

CMakeFiles/warpAffine.dir/7.45.cpp.o.requires:
.PHONY : CMakeFiles/warpAffine.dir/7.45.cpp.o.requires

CMakeFiles/warpAffine.dir/7.45.cpp.o.provides: CMakeFiles/warpAffine.dir/7.45.cpp.o.requires
	$(MAKE) -f CMakeFiles/warpAffine.dir/build.make CMakeFiles/warpAffine.dir/7.45.cpp.o.provides.build
.PHONY : CMakeFiles/warpAffine.dir/7.45.cpp.o.provides

CMakeFiles/warpAffine.dir/7.45.cpp.o.provides.build: CMakeFiles/warpAffine.dir/7.45.cpp.o

# Object files for target warpAffine
warpAffine_OBJECTS = \
"CMakeFiles/warpAffine.dir/7.45.cpp.o"

# External object files for target warpAffine
warpAffine_EXTERNAL_OBJECTS =

warpAffine: CMakeFiles/warpAffine.dir/7.45.cpp.o
warpAffine: CMakeFiles/warpAffine.dir/build.make
warpAffine: /usr/local/lib/libopencv_viz.so.3.1.0
warpAffine: /usr/local/lib/libopencv_videostab.so.3.1.0
warpAffine: /usr/local/lib/libopencv_videoio.so.3.1.0
warpAffine: /usr/local/lib/libopencv_video.so.3.1.0
warpAffine: /usr/local/lib/libopencv_superres.so.3.1.0
warpAffine: /usr/local/lib/libopencv_stitching.so.3.1.0
warpAffine: /usr/local/lib/libopencv_shape.so.3.1.0
warpAffine: /usr/local/lib/libopencv_photo.so.3.1.0
warpAffine: /usr/local/lib/libopencv_objdetect.so.3.1.0
warpAffine: /usr/local/lib/libopencv_ml.so.3.1.0
warpAffine: /usr/local/lib/libopencv_imgproc.so.3.1.0
warpAffine: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
warpAffine: /usr/local/lib/libopencv_highgui.so.3.1.0
warpAffine: /usr/local/lib/libopencv_flann.so.3.1.0
warpAffine: /usr/local/lib/libopencv_features2d.so.3.1.0
warpAffine: /usr/local/lib/libopencv_core.so.3.1.0
warpAffine: /usr/local/lib/libopencv_calib3d.so.3.1.0
warpAffine: /usr/local/lib/libopencv_features2d.so.3.1.0
warpAffine: /usr/local/lib/libopencv_ml.so.3.1.0
warpAffine: /usr/local/lib/libopencv_highgui.so.3.1.0
warpAffine: /usr/local/lib/libopencv_videoio.so.3.1.0
warpAffine: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
warpAffine: /usr/local/lib/libopencv_flann.so.3.1.0
warpAffine: /usr/local/lib/libopencv_video.so.3.1.0
warpAffine: /usr/local/lib/libopencv_imgproc.so.3.1.0
warpAffine: /usr/local/lib/libopencv_core.so.3.1.0
warpAffine: CMakeFiles/warpAffine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable warpAffine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/warpAffine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/warpAffine.dir/build: warpAffine
.PHONY : CMakeFiles/warpAffine.dir/build

CMakeFiles/warpAffine.dir/requires: CMakeFiles/warpAffine.dir/7.45.cpp.o.requires
.PHONY : CMakeFiles/warpAffine.dir/requires

CMakeFiles/warpAffine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/warpAffine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/warpAffine.dir/clean

CMakeFiles/warpAffine.dir/depend:
	cd /home/lkf/Code/OpenCV/opencv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lkf/Code/OpenCV/opencv /home/lkf/Code/OpenCV/opencv /home/lkf/Code/OpenCV/opencv/build /home/lkf/Code/OpenCV/opencv/build /home/lkf/Code/OpenCV/opencv/build/CMakeFiles/warpAffine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/warpAffine.dir/depend

