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
include CMakeFiles/Shi_Tomasi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Shi_Tomasi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Shi_Tomasi.dir/flags.make

CMakeFiles/Shi_Tomasi.dir/10.23.cpp.o: CMakeFiles/Shi_Tomasi.dir/flags.make
CMakeFiles/Shi_Tomasi.dir/10.23.cpp.o: ../10.23.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lkf/Code/OpenCV/opencv/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Shi_Tomasi.dir/10.23.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Shi_Tomasi.dir/10.23.cpp.o -c /home/lkf/Code/OpenCV/opencv/10.23.cpp

CMakeFiles/Shi_Tomasi.dir/10.23.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Shi_Tomasi.dir/10.23.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lkf/Code/OpenCV/opencv/10.23.cpp > CMakeFiles/Shi_Tomasi.dir/10.23.cpp.i

CMakeFiles/Shi_Tomasi.dir/10.23.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Shi_Tomasi.dir/10.23.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lkf/Code/OpenCV/opencv/10.23.cpp -o CMakeFiles/Shi_Tomasi.dir/10.23.cpp.s

CMakeFiles/Shi_Tomasi.dir/10.23.cpp.o.requires:
.PHONY : CMakeFiles/Shi_Tomasi.dir/10.23.cpp.o.requires

CMakeFiles/Shi_Tomasi.dir/10.23.cpp.o.provides: CMakeFiles/Shi_Tomasi.dir/10.23.cpp.o.requires
	$(MAKE) -f CMakeFiles/Shi_Tomasi.dir/build.make CMakeFiles/Shi_Tomasi.dir/10.23.cpp.o.provides.build
.PHONY : CMakeFiles/Shi_Tomasi.dir/10.23.cpp.o.provides

CMakeFiles/Shi_Tomasi.dir/10.23.cpp.o.provides.build: CMakeFiles/Shi_Tomasi.dir/10.23.cpp.o

# Object files for target Shi_Tomasi
Shi_Tomasi_OBJECTS = \
"CMakeFiles/Shi_Tomasi.dir/10.23.cpp.o"

# External object files for target Shi_Tomasi
Shi_Tomasi_EXTERNAL_OBJECTS =

Shi_Tomasi: CMakeFiles/Shi_Tomasi.dir/10.23.cpp.o
Shi_Tomasi: CMakeFiles/Shi_Tomasi.dir/build.make
Shi_Tomasi: /usr/local/lib/libopencv_viz.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_videostab.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_videoio.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_video.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_superres.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_stitching.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_shape.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_photo.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_objdetect.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_ml.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_imgproc.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_highgui.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_flann.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_features2d.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_core.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_calib3d.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_features2d.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_ml.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_highgui.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_videoio.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_flann.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_video.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_imgproc.so.3.1.0
Shi_Tomasi: /usr/local/lib/libopencv_core.so.3.1.0
Shi_Tomasi: CMakeFiles/Shi_Tomasi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Shi_Tomasi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Shi_Tomasi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Shi_Tomasi.dir/build: Shi_Tomasi
.PHONY : CMakeFiles/Shi_Tomasi.dir/build

CMakeFiles/Shi_Tomasi.dir/requires: CMakeFiles/Shi_Tomasi.dir/10.23.cpp.o.requires
.PHONY : CMakeFiles/Shi_Tomasi.dir/requires

CMakeFiles/Shi_Tomasi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Shi_Tomasi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Shi_Tomasi.dir/clean

CMakeFiles/Shi_Tomasi.dir/depend:
	cd /home/lkf/Code/OpenCV/opencv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lkf/Code/OpenCV/opencv /home/lkf/Code/OpenCV/opencv /home/lkf/Code/OpenCV/opencv/build /home/lkf/Code/OpenCV/opencv/build /home/lkf/Code/OpenCV/opencv/build/CMakeFiles/Shi_Tomasi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Shi_Tomasi.dir/depend

