# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/unre/Desktop/gm_open

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/unre/Desktop/gm_open

# Include any dependencies generated for this target.
include CMakeFiles/gmopen.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gmopen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gmopen.dir/flags.make

CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.o: CMakeFiles/gmopen.dir/flags.make
CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.o: src/gui/glcolor.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.o -c /home/unre/Desktop/gm_open/src/gui/glcolor.cpp

CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/unre/Desktop/gm_open/src/gui/glcolor.cpp > CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.i

CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/unre/Desktop/gm_open/src/gui/glcolor.cpp -o CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.s

CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.o.requires:
.PHONY : CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.o.requires

CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.o.provides: CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.o.requires
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.o.provides.build
.PHONY : CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.o.provides

CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.o.provides.build: CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.o
.PHONY : CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.o.provides.build

CMakeFiles/gmopen.dir/src/gui/triangle.cpp.o: CMakeFiles/gmopen.dir/flags.make
CMakeFiles/gmopen.dir/src/gui/triangle.cpp.o: src/gui/triangle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmopen.dir/src/gui/triangle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmopen.dir/src/gui/triangle.cpp.o -c /home/unre/Desktop/gm_open/src/gui/triangle.cpp

CMakeFiles/gmopen.dir/src/gui/triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmopen.dir/src/gui/triangle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/unre/Desktop/gm_open/src/gui/triangle.cpp > CMakeFiles/gmopen.dir/src/gui/triangle.cpp.i

CMakeFiles/gmopen.dir/src/gui/triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmopen.dir/src/gui/triangle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/unre/Desktop/gm_open/src/gui/triangle.cpp -o CMakeFiles/gmopen.dir/src/gui/triangle.cpp.s

CMakeFiles/gmopen.dir/src/gui/triangle.cpp.o.requires:
.PHONY : CMakeFiles/gmopen.dir/src/gui/triangle.cpp.o.requires

CMakeFiles/gmopen.dir/src/gui/triangle.cpp.o.provides: CMakeFiles/gmopen.dir/src/gui/triangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/triangle.cpp.o.provides.build
.PHONY : CMakeFiles/gmopen.dir/src/gui/triangle.cpp.o.provides

CMakeFiles/gmopen.dir/src/gui/triangle.cpp.o.provides.build: CMakeFiles/gmopen.dir/src/gui/triangle.cpp.o
.PHONY : CMakeFiles/gmopen.dir/src/gui/triangle.cpp.o.provides.build

CMakeFiles/gmopen.dir/src/gui/vertex.cpp.o: CMakeFiles/gmopen.dir/flags.make
CMakeFiles/gmopen.dir/src/gui/vertex.cpp.o: src/gui/vertex.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmopen.dir/src/gui/vertex.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmopen.dir/src/gui/vertex.cpp.o -c /home/unre/Desktop/gm_open/src/gui/vertex.cpp

CMakeFiles/gmopen.dir/src/gui/vertex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmopen.dir/src/gui/vertex.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/unre/Desktop/gm_open/src/gui/vertex.cpp > CMakeFiles/gmopen.dir/src/gui/vertex.cpp.i

CMakeFiles/gmopen.dir/src/gui/vertex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmopen.dir/src/gui/vertex.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/unre/Desktop/gm_open/src/gui/vertex.cpp -o CMakeFiles/gmopen.dir/src/gui/vertex.cpp.s

CMakeFiles/gmopen.dir/src/gui/vertex.cpp.o.requires:
.PHONY : CMakeFiles/gmopen.dir/src/gui/vertex.cpp.o.requires

CMakeFiles/gmopen.dir/src/gui/vertex.cpp.o.provides: CMakeFiles/gmopen.dir/src/gui/vertex.cpp.o.requires
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/vertex.cpp.o.provides.build
.PHONY : CMakeFiles/gmopen.dir/src/gui/vertex.cpp.o.provides

CMakeFiles/gmopen.dir/src/gui/vertex.cpp.o.provides.build: CMakeFiles/gmopen.dir/src/gui/vertex.cpp.o
.PHONY : CMakeFiles/gmopen.dir/src/gui/vertex.cpp.o.provides.build

CMakeFiles/gmopen.dir/src/gui/mesh.cpp.o: CMakeFiles/gmopen.dir/flags.make
CMakeFiles/gmopen.dir/src/gui/mesh.cpp.o: src/gui/mesh.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmopen.dir/src/gui/mesh.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmopen.dir/src/gui/mesh.cpp.o -c /home/unre/Desktop/gm_open/src/gui/mesh.cpp

CMakeFiles/gmopen.dir/src/gui/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmopen.dir/src/gui/mesh.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/unre/Desktop/gm_open/src/gui/mesh.cpp > CMakeFiles/gmopen.dir/src/gui/mesh.cpp.i

CMakeFiles/gmopen.dir/src/gui/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmopen.dir/src/gui/mesh.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/unre/Desktop/gm_open/src/gui/mesh.cpp -o CMakeFiles/gmopen.dir/src/gui/mesh.cpp.s

CMakeFiles/gmopen.dir/src/gui/mesh.cpp.o.requires:
.PHONY : CMakeFiles/gmopen.dir/src/gui/mesh.cpp.o.requires

CMakeFiles/gmopen.dir/src/gui/mesh.cpp.o.provides: CMakeFiles/gmopen.dir/src/gui/mesh.cpp.o.requires
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/mesh.cpp.o.provides.build
.PHONY : CMakeFiles/gmopen.dir/src/gui/mesh.cpp.o.provides

CMakeFiles/gmopen.dir/src/gui/mesh.cpp.o.provides.build: CMakeFiles/gmopen.dir/src/gui/mesh.cpp.o
.PHONY : CMakeFiles/gmopen.dir/src/gui/mesh.cpp.o.provides.build

CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.o: CMakeFiles/gmopen.dir/flags.make
CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.o: src/gui/glviewer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.o -c /home/unre/Desktop/gm_open/src/gui/glviewer.cpp

CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/unre/Desktop/gm_open/src/gui/glviewer.cpp > CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.i

CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/unre/Desktop/gm_open/src/gui/glviewer.cpp -o CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.s

CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.o.requires:
.PHONY : CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.o.requires

CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.o.provides: CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.o.requires
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.o.provides.build
.PHONY : CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.o.provides

CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.o.provides.build: CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.o
.PHONY : CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.o.provides.build

CMakeFiles/gmopen.dir/src/gui/window.cpp.o: CMakeFiles/gmopen.dir/flags.make
CMakeFiles/gmopen.dir/src/gui/window.cpp.o: src/gui/window.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmopen.dir/src/gui/window.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmopen.dir/src/gui/window.cpp.o -c /home/unre/Desktop/gm_open/src/gui/window.cpp

CMakeFiles/gmopen.dir/src/gui/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmopen.dir/src/gui/window.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/unre/Desktop/gm_open/src/gui/window.cpp > CMakeFiles/gmopen.dir/src/gui/window.cpp.i

CMakeFiles/gmopen.dir/src/gui/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmopen.dir/src/gui/window.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/unre/Desktop/gm_open/src/gui/window.cpp -o CMakeFiles/gmopen.dir/src/gui/window.cpp.s

CMakeFiles/gmopen.dir/src/gui/window.cpp.o.requires:
.PHONY : CMakeFiles/gmopen.dir/src/gui/window.cpp.o.requires

CMakeFiles/gmopen.dir/src/gui/window.cpp.o.provides: CMakeFiles/gmopen.dir/src/gui/window.cpp.o.requires
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/window.cpp.o.provides.build
.PHONY : CMakeFiles/gmopen.dir/src/gui/window.cpp.o.provides

CMakeFiles/gmopen.dir/src/gui/window.cpp.o.provides.build: CMakeFiles/gmopen.dir/src/gui/window.cpp.o
.PHONY : CMakeFiles/gmopen.dir/src/gui/window.cpp.o.provides.build

CMakeFiles/gmopen.dir/src/main.cpp.o: CMakeFiles/gmopen.dir/flags.make
CMakeFiles/gmopen.dir/src/main.cpp.o: src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmopen.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmopen.dir/src/main.cpp.o -c /home/unre/Desktop/gm_open/src/main.cpp

CMakeFiles/gmopen.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmopen.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/unre/Desktop/gm_open/src/main.cpp > CMakeFiles/gmopen.dir/src/main.cpp.i

CMakeFiles/gmopen.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmopen.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/unre/Desktop/gm_open/src/main.cpp -o CMakeFiles/gmopen.dir/src/main.cpp.s

CMakeFiles/gmopen.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/gmopen.dir/src/main.cpp.o.requires

CMakeFiles/gmopen.dir/src/main.cpp.o.provides: CMakeFiles/gmopen.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/gmopen.dir/src/main.cpp.o.provides

CMakeFiles/gmopen.dir/src/main.cpp.o.provides.build: CMakeFiles/gmopen.dir/src/main.cpp.o
.PHONY : CMakeFiles/gmopen.dir/src/main.cpp.o.provides.build

CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.o: CMakeFiles/gmopen.dir/flags.make
CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.o: src/gui/moc_glcolor.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.o -c /home/unre/Desktop/gm_open/src/gui/moc_glcolor.cxx

CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/unre/Desktop/gm_open/src/gui/moc_glcolor.cxx > CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.i

CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/unre/Desktop/gm_open/src/gui/moc_glcolor.cxx -o CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.s

CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.o.requires:
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.o.requires

CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.o.provides: CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.o.requires
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.o.provides.build
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.o.provides

CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.o.provides.build: CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.o
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.o.provides.build

CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.o: CMakeFiles/gmopen.dir/flags.make
CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.o: src/gui/moc_vec3D.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.o -c /home/unre/Desktop/gm_open/src/gui/moc_vec3D.cxx

CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/unre/Desktop/gm_open/src/gui/moc_vec3D.cxx > CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.i

CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/unre/Desktop/gm_open/src/gui/moc_vec3D.cxx -o CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.s

CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.o.requires:
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.o.requires

CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.o.provides: CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.o.requires
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.o.provides.build
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.o.provides

CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.o.provides.build: CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.o
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.o.provides.build

CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.o: CMakeFiles/gmopen.dir/flags.make
CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.o: src/gui/moc_triangle.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.o -c /home/unre/Desktop/gm_open/src/gui/moc_triangle.cxx

CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/unre/Desktop/gm_open/src/gui/moc_triangle.cxx > CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.i

CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/unre/Desktop/gm_open/src/gui/moc_triangle.cxx -o CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.s

CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.o.requires:
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.o.requires

CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.o.provides: CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.o.requires
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.o.provides.build
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.o.provides

CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.o.provides.build: CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.o
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.o.provides.build

CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.o: CMakeFiles/gmopen.dir/flags.make
CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.o: src/gui/moc_vertex.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.o -c /home/unre/Desktop/gm_open/src/gui/moc_vertex.cxx

CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/unre/Desktop/gm_open/src/gui/moc_vertex.cxx > CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.i

CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/unre/Desktop/gm_open/src/gui/moc_vertex.cxx -o CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.s

CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.o.requires:
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.o.requires

CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.o.provides: CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.o.requires
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.o.provides.build
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.o.provides

CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.o.provides.build: CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.o
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.o.provides.build

CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.o: CMakeFiles/gmopen.dir/flags.make
CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.o: src/gui/moc_edge.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.o -c /home/unre/Desktop/gm_open/src/gui/moc_edge.cxx

CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/unre/Desktop/gm_open/src/gui/moc_edge.cxx > CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.i

CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/unre/Desktop/gm_open/src/gui/moc_edge.cxx -o CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.s

CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.o.requires:
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.o.requires

CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.o.provides: CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.o.requires
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.o.provides.build
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.o.provides

CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.o.provides.build: CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.o
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.o.provides.build

CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.o: CMakeFiles/gmopen.dir/flags.make
CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.o: src/gui/moc_mesh.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.o -c /home/unre/Desktop/gm_open/src/gui/moc_mesh.cxx

CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/unre/Desktop/gm_open/src/gui/moc_mesh.cxx > CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.i

CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/unre/Desktop/gm_open/src/gui/moc_mesh.cxx -o CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.s

CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.o.requires:
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.o.requires

CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.o.provides: CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.o.requires
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.o.provides.build
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.o.provides

CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.o.provides.build: CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.o
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.o.provides.build

CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.o: CMakeFiles/gmopen.dir/flags.make
CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.o: src/gui/moc_glviewer.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_14)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.o -c /home/unre/Desktop/gm_open/src/gui/moc_glviewer.cxx

CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/unre/Desktop/gm_open/src/gui/moc_glviewer.cxx > CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.i

CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/unre/Desktop/gm_open/src/gui/moc_glviewer.cxx -o CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.s

CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.o.requires:
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.o.requires

CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.o.provides: CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.o.requires
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.o.provides.build
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.o.provides

CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.o.provides.build: CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.o
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.o.provides.build

CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.o: CMakeFiles/gmopen.dir/flags.make
CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.o: src/gui/moc_window.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_15)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.o -c /home/unre/Desktop/gm_open/src/gui/moc_window.cxx

CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/unre/Desktop/gm_open/src/gui/moc_window.cxx > CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.i

CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/unre/Desktop/gm_open/src/gui/moc_window.cxx -o CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.s

CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.o.requires:
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.o.requires

CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.o.provides: CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.o.requires
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.o.provides.build
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.o.provides

CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.o.provides.build: CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.o
.PHONY : CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.o.provides.build

src/gui/moc_glcolor.cxx: src/gui/glcolor.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_16)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating src/gui/moc_glcolor.cxx"
	/usr/bin/moc -I/usr/local/include -I/usr/include/libusb-1.0 -I/driver -I/usr/include -o /home/unre/Desktop/gm_open/src/gui/moc_glcolor.cxx /home/unre/Desktop/gm_open/src/gui/glcolor.h

src/gui/moc_vec3D.cxx: src/gui/vec3D.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_17)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating src/gui/moc_vec3D.cxx"
	/usr/bin/moc -I/usr/local/include -I/usr/include/libusb-1.0 -I/driver -I/usr/include -o /home/unre/Desktop/gm_open/src/gui/moc_vec3D.cxx /home/unre/Desktop/gm_open/src/gui/vec3D.h

src/gui/moc_triangle.cxx: src/gui/triangle.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_18)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating src/gui/moc_triangle.cxx"
	/usr/bin/moc -I/usr/local/include -I/usr/include/libusb-1.0 -I/driver -I/usr/include -o /home/unre/Desktop/gm_open/src/gui/moc_triangle.cxx /home/unre/Desktop/gm_open/src/gui/triangle.h

src/gui/moc_vertex.cxx: src/gui/vertex.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_19)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating src/gui/moc_vertex.cxx"
	/usr/bin/moc -I/usr/local/include -I/usr/include/libusb-1.0 -I/driver -I/usr/include -o /home/unre/Desktop/gm_open/src/gui/moc_vertex.cxx /home/unre/Desktop/gm_open/src/gui/vertex.h

src/gui/moc_edge.cxx: src/gui/edge.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_20)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating src/gui/moc_edge.cxx"
	/usr/bin/moc -I/usr/local/include -I/usr/include/libusb-1.0 -I/driver -I/usr/include -o /home/unre/Desktop/gm_open/src/gui/moc_edge.cxx /home/unre/Desktop/gm_open/src/gui/edge.h

src/gui/moc_mesh.cxx: src/gui/mesh.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_21)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating src/gui/moc_mesh.cxx"
	/usr/bin/moc -I/usr/local/include -I/usr/include/libusb-1.0 -I/driver -I/usr/include -o /home/unre/Desktop/gm_open/src/gui/moc_mesh.cxx /home/unre/Desktop/gm_open/src/gui/mesh.h

src/gui/moc_glviewer.cxx: src/gui/glviewer.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_22)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating src/gui/moc_glviewer.cxx"
	/usr/bin/moc -I/usr/local/include -I/usr/include/libusb-1.0 -I/driver -I/usr/include -o /home/unre/Desktop/gm_open/src/gui/moc_glviewer.cxx /home/unre/Desktop/gm_open/src/gui/glviewer.h

src/gui/moc_window.cxx: src/gui/window.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/unre/Desktop/gm_open/CMakeFiles $(CMAKE_PROGRESS_23)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating src/gui/moc_window.cxx"
	/usr/bin/moc -I/usr/local/include -I/usr/include/libusb-1.0 -I/driver -I/usr/include -o /home/unre/Desktop/gm_open/src/gui/moc_window.cxx /home/unre/Desktop/gm_open/src/gui/window.h

# Object files for target gmopen
gmopen_OBJECTS = \
"CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.o" \
"CMakeFiles/gmopen.dir/src/gui/triangle.cpp.o" \
"CMakeFiles/gmopen.dir/src/gui/vertex.cpp.o" \
"CMakeFiles/gmopen.dir/src/gui/mesh.cpp.o" \
"CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.o" \
"CMakeFiles/gmopen.dir/src/gui/window.cpp.o" \
"CMakeFiles/gmopen.dir/src/main.cpp.o" \
"CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.o" \
"CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.o" \
"CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.o" \
"CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.o" \
"CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.o" \
"CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.o" \
"CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.o" \
"CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.o"

# External object files for target gmopen
gmopen_EXTERNAL_OBJECTS =

gmopen: CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.o
gmopen: CMakeFiles/gmopen.dir/src/gui/triangle.cpp.o
gmopen: CMakeFiles/gmopen.dir/src/gui/vertex.cpp.o
gmopen: CMakeFiles/gmopen.dir/src/gui/mesh.cpp.o
gmopen: CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.o
gmopen: CMakeFiles/gmopen.dir/src/gui/window.cpp.o
gmopen: CMakeFiles/gmopen.dir/src/main.cpp.o
gmopen: CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.o
gmopen: CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.o
gmopen: CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.o
gmopen: CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.o
gmopen: CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.o
gmopen: CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.o
gmopen: CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.o
gmopen: CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.o
gmopen: /usr/lib/libmcrypt.so
gmopen: /usr/lib/libusb-1.0.so
gmopen: /usr/lib/libQtOpenGL.so
gmopen: /usr/lib/libQtGui.so
gmopen: /usr/lib/libQtCore.so
gmopen: /usr/lib/libQtOpenGL.so
gmopen: /usr/lib/libQGLViewer.so
gmopen: /usr/lib/libQtGui.so
gmopen: /usr/lib/libQtCore.so
gmopen: /usr/lib/libQGLViewer.so
gmopen: CMakeFiles/gmopen.dir/build.make
gmopen: CMakeFiles/gmopen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable gmopen"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmopen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gmopen.dir/build: gmopen
.PHONY : CMakeFiles/gmopen.dir/build

CMakeFiles/gmopen.dir/requires: CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.o.requires
CMakeFiles/gmopen.dir/requires: CMakeFiles/gmopen.dir/src/gui/triangle.cpp.o.requires
CMakeFiles/gmopen.dir/requires: CMakeFiles/gmopen.dir/src/gui/vertex.cpp.o.requires
CMakeFiles/gmopen.dir/requires: CMakeFiles/gmopen.dir/src/gui/mesh.cpp.o.requires
CMakeFiles/gmopen.dir/requires: CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.o.requires
CMakeFiles/gmopen.dir/requires: CMakeFiles/gmopen.dir/src/gui/window.cpp.o.requires
CMakeFiles/gmopen.dir/requires: CMakeFiles/gmopen.dir/src/main.cpp.o.requires
CMakeFiles/gmopen.dir/requires: CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.o.requires
CMakeFiles/gmopen.dir/requires: CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.o.requires
CMakeFiles/gmopen.dir/requires: CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.o.requires
CMakeFiles/gmopen.dir/requires: CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.o.requires
CMakeFiles/gmopen.dir/requires: CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.o.requires
CMakeFiles/gmopen.dir/requires: CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.o.requires
CMakeFiles/gmopen.dir/requires: CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.o.requires
CMakeFiles/gmopen.dir/requires: CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.o.requires
.PHONY : CMakeFiles/gmopen.dir/requires

CMakeFiles/gmopen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gmopen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gmopen.dir/clean

CMakeFiles/gmopen.dir/depend: src/gui/moc_glcolor.cxx
CMakeFiles/gmopen.dir/depend: src/gui/moc_vec3D.cxx
CMakeFiles/gmopen.dir/depend: src/gui/moc_triangle.cxx
CMakeFiles/gmopen.dir/depend: src/gui/moc_vertex.cxx
CMakeFiles/gmopen.dir/depend: src/gui/moc_edge.cxx
CMakeFiles/gmopen.dir/depend: src/gui/moc_mesh.cxx
CMakeFiles/gmopen.dir/depend: src/gui/moc_glviewer.cxx
CMakeFiles/gmopen.dir/depend: src/gui/moc_window.cxx
	cd /home/unre/Desktop/gm_open && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/unre/Desktop/gm_open /home/unre/Desktop/gm_open /home/unre/Desktop/gm_open /home/unre/Desktop/gm_open /home/unre/Desktop/gm_open/CMakeFiles/gmopen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gmopen.dir/depend

