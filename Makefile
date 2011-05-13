# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/unre/Desktop/gm_open/CMakeFiles /home/unre/Desktop/gm_open/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/unre/Desktop/gm_open/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named gmopen

# Build rule for target.
gmopen: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gmopen
.PHONY : gmopen

# fast build rule for target.
gmopen/fast:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/build
.PHONY : gmopen/fast

src/gui/glcolor.o: src/gui/glcolor.cpp.o
.PHONY : src/gui/glcolor.o

# target to build an object file
src/gui/glcolor.cpp.o:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.o
.PHONY : src/gui/glcolor.cpp.o

src/gui/glcolor.i: src/gui/glcolor.cpp.i
.PHONY : src/gui/glcolor.i

# target to preprocess a source file
src/gui/glcolor.cpp.i:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.i
.PHONY : src/gui/glcolor.cpp.i

src/gui/glcolor.s: src/gui/glcolor.cpp.s
.PHONY : src/gui/glcolor.s

# target to generate assembly for a file
src/gui/glcolor.cpp.s:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/glcolor.cpp.s
.PHONY : src/gui/glcolor.cpp.s

src/gui/glviewer.o: src/gui/glviewer.cpp.o
.PHONY : src/gui/glviewer.o

# target to build an object file
src/gui/glviewer.cpp.o:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.o
.PHONY : src/gui/glviewer.cpp.o

src/gui/glviewer.i: src/gui/glviewer.cpp.i
.PHONY : src/gui/glviewer.i

# target to preprocess a source file
src/gui/glviewer.cpp.i:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.i
.PHONY : src/gui/glviewer.cpp.i

src/gui/glviewer.s: src/gui/glviewer.cpp.s
.PHONY : src/gui/glviewer.s

# target to generate assembly for a file
src/gui/glviewer.cpp.s:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/glviewer.cpp.s
.PHONY : src/gui/glviewer.cpp.s

src/gui/mesh.o: src/gui/mesh.cpp.o
.PHONY : src/gui/mesh.o

# target to build an object file
src/gui/mesh.cpp.o:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/mesh.cpp.o
.PHONY : src/gui/mesh.cpp.o

src/gui/mesh.i: src/gui/mesh.cpp.i
.PHONY : src/gui/mesh.i

# target to preprocess a source file
src/gui/mesh.cpp.i:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/mesh.cpp.i
.PHONY : src/gui/mesh.cpp.i

src/gui/mesh.s: src/gui/mesh.cpp.s
.PHONY : src/gui/mesh.s

# target to generate assembly for a file
src/gui/mesh.cpp.s:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/mesh.cpp.s
.PHONY : src/gui/mesh.cpp.s

src/gui/moc_edge.o: src/gui/moc_edge.cxx.o
.PHONY : src/gui/moc_edge.o

# target to build an object file
src/gui/moc_edge.cxx.o:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.o
.PHONY : src/gui/moc_edge.cxx.o

src/gui/moc_edge.i: src/gui/moc_edge.cxx.i
.PHONY : src/gui/moc_edge.i

# target to preprocess a source file
src/gui/moc_edge.cxx.i:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.i
.PHONY : src/gui/moc_edge.cxx.i

src/gui/moc_edge.s: src/gui/moc_edge.cxx.s
.PHONY : src/gui/moc_edge.s

# target to generate assembly for a file
src/gui/moc_edge.cxx.s:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_edge.cxx.s
.PHONY : src/gui/moc_edge.cxx.s

src/gui/moc_glcolor.o: src/gui/moc_glcolor.cxx.o
.PHONY : src/gui/moc_glcolor.o

# target to build an object file
src/gui/moc_glcolor.cxx.o:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.o
.PHONY : src/gui/moc_glcolor.cxx.o

src/gui/moc_glcolor.i: src/gui/moc_glcolor.cxx.i
.PHONY : src/gui/moc_glcolor.i

# target to preprocess a source file
src/gui/moc_glcolor.cxx.i:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.i
.PHONY : src/gui/moc_glcolor.cxx.i

src/gui/moc_glcolor.s: src/gui/moc_glcolor.cxx.s
.PHONY : src/gui/moc_glcolor.s

# target to generate assembly for a file
src/gui/moc_glcolor.cxx.s:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_glcolor.cxx.s
.PHONY : src/gui/moc_glcolor.cxx.s

src/gui/moc_glviewer.o: src/gui/moc_glviewer.cxx.o
.PHONY : src/gui/moc_glviewer.o

# target to build an object file
src/gui/moc_glviewer.cxx.o:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.o
.PHONY : src/gui/moc_glviewer.cxx.o

src/gui/moc_glviewer.i: src/gui/moc_glviewer.cxx.i
.PHONY : src/gui/moc_glviewer.i

# target to preprocess a source file
src/gui/moc_glviewer.cxx.i:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.i
.PHONY : src/gui/moc_glviewer.cxx.i

src/gui/moc_glviewer.s: src/gui/moc_glviewer.cxx.s
.PHONY : src/gui/moc_glviewer.s

# target to generate assembly for a file
src/gui/moc_glviewer.cxx.s:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_glviewer.cxx.s
.PHONY : src/gui/moc_glviewer.cxx.s

src/gui/moc_mesh.o: src/gui/moc_mesh.cxx.o
.PHONY : src/gui/moc_mesh.o

# target to build an object file
src/gui/moc_mesh.cxx.o:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.o
.PHONY : src/gui/moc_mesh.cxx.o

src/gui/moc_mesh.i: src/gui/moc_mesh.cxx.i
.PHONY : src/gui/moc_mesh.i

# target to preprocess a source file
src/gui/moc_mesh.cxx.i:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.i
.PHONY : src/gui/moc_mesh.cxx.i

src/gui/moc_mesh.s: src/gui/moc_mesh.cxx.s
.PHONY : src/gui/moc_mesh.s

# target to generate assembly for a file
src/gui/moc_mesh.cxx.s:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_mesh.cxx.s
.PHONY : src/gui/moc_mesh.cxx.s

src/gui/moc_triangle.o: src/gui/moc_triangle.cxx.o
.PHONY : src/gui/moc_triangle.o

# target to build an object file
src/gui/moc_triangle.cxx.o:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.o
.PHONY : src/gui/moc_triangle.cxx.o

src/gui/moc_triangle.i: src/gui/moc_triangle.cxx.i
.PHONY : src/gui/moc_triangle.i

# target to preprocess a source file
src/gui/moc_triangle.cxx.i:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.i
.PHONY : src/gui/moc_triangle.cxx.i

src/gui/moc_triangle.s: src/gui/moc_triangle.cxx.s
.PHONY : src/gui/moc_triangle.s

# target to generate assembly for a file
src/gui/moc_triangle.cxx.s:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_triangle.cxx.s
.PHONY : src/gui/moc_triangle.cxx.s

src/gui/moc_vec3D.o: src/gui/moc_vec3D.cxx.o
.PHONY : src/gui/moc_vec3D.o

# target to build an object file
src/gui/moc_vec3D.cxx.o:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.o
.PHONY : src/gui/moc_vec3D.cxx.o

src/gui/moc_vec3D.i: src/gui/moc_vec3D.cxx.i
.PHONY : src/gui/moc_vec3D.i

# target to preprocess a source file
src/gui/moc_vec3D.cxx.i:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.i
.PHONY : src/gui/moc_vec3D.cxx.i

src/gui/moc_vec3D.s: src/gui/moc_vec3D.cxx.s
.PHONY : src/gui/moc_vec3D.s

# target to generate assembly for a file
src/gui/moc_vec3D.cxx.s:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_vec3D.cxx.s
.PHONY : src/gui/moc_vec3D.cxx.s

src/gui/moc_vertex.o: src/gui/moc_vertex.cxx.o
.PHONY : src/gui/moc_vertex.o

# target to build an object file
src/gui/moc_vertex.cxx.o:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.o
.PHONY : src/gui/moc_vertex.cxx.o

src/gui/moc_vertex.i: src/gui/moc_vertex.cxx.i
.PHONY : src/gui/moc_vertex.i

# target to preprocess a source file
src/gui/moc_vertex.cxx.i:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.i
.PHONY : src/gui/moc_vertex.cxx.i

src/gui/moc_vertex.s: src/gui/moc_vertex.cxx.s
.PHONY : src/gui/moc_vertex.s

# target to generate assembly for a file
src/gui/moc_vertex.cxx.s:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_vertex.cxx.s
.PHONY : src/gui/moc_vertex.cxx.s

src/gui/moc_window.o: src/gui/moc_window.cxx.o
.PHONY : src/gui/moc_window.o

# target to build an object file
src/gui/moc_window.cxx.o:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.o
.PHONY : src/gui/moc_window.cxx.o

src/gui/moc_window.i: src/gui/moc_window.cxx.i
.PHONY : src/gui/moc_window.i

# target to preprocess a source file
src/gui/moc_window.cxx.i:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.i
.PHONY : src/gui/moc_window.cxx.i

src/gui/moc_window.s: src/gui/moc_window.cxx.s
.PHONY : src/gui/moc_window.s

# target to generate assembly for a file
src/gui/moc_window.cxx.s:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/moc_window.cxx.s
.PHONY : src/gui/moc_window.cxx.s

src/gui/triangle.o: src/gui/triangle.cpp.o
.PHONY : src/gui/triangle.o

# target to build an object file
src/gui/triangle.cpp.o:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/triangle.cpp.o
.PHONY : src/gui/triangle.cpp.o

src/gui/triangle.i: src/gui/triangle.cpp.i
.PHONY : src/gui/triangle.i

# target to preprocess a source file
src/gui/triangle.cpp.i:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/triangle.cpp.i
.PHONY : src/gui/triangle.cpp.i

src/gui/triangle.s: src/gui/triangle.cpp.s
.PHONY : src/gui/triangle.s

# target to generate assembly for a file
src/gui/triangle.cpp.s:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/triangle.cpp.s
.PHONY : src/gui/triangle.cpp.s

src/gui/vertex.o: src/gui/vertex.cpp.o
.PHONY : src/gui/vertex.o

# target to build an object file
src/gui/vertex.cpp.o:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/vertex.cpp.o
.PHONY : src/gui/vertex.cpp.o

src/gui/vertex.i: src/gui/vertex.cpp.i
.PHONY : src/gui/vertex.i

# target to preprocess a source file
src/gui/vertex.cpp.i:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/vertex.cpp.i
.PHONY : src/gui/vertex.cpp.i

src/gui/vertex.s: src/gui/vertex.cpp.s
.PHONY : src/gui/vertex.s

# target to generate assembly for a file
src/gui/vertex.cpp.s:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/vertex.cpp.s
.PHONY : src/gui/vertex.cpp.s

src/gui/window.o: src/gui/window.cpp.o
.PHONY : src/gui/window.o

# target to build an object file
src/gui/window.cpp.o:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/window.cpp.o
.PHONY : src/gui/window.cpp.o

src/gui/window.i: src/gui/window.cpp.i
.PHONY : src/gui/window.i

# target to preprocess a source file
src/gui/window.cpp.i:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/window.cpp.i
.PHONY : src/gui/window.cpp.i

src/gui/window.s: src/gui/window.cpp.s
.PHONY : src/gui/window.s

# target to generate assembly for a file
src/gui/window.cpp.s:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/gui/window.cpp.s
.PHONY : src/gui/window.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/gmopen.dir/build.make CMakeFiles/gmopen.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... gmopen"
	@echo "... rebuild_cache"
	@echo "... src/gui/glcolor.o"
	@echo "... src/gui/glcolor.i"
	@echo "... src/gui/glcolor.s"
	@echo "... src/gui/glviewer.o"
	@echo "... src/gui/glviewer.i"
	@echo "... src/gui/glviewer.s"
	@echo "... src/gui/mesh.o"
	@echo "... src/gui/mesh.i"
	@echo "... src/gui/mesh.s"
	@echo "... src/gui/moc_edge.o"
	@echo "... src/gui/moc_edge.i"
	@echo "... src/gui/moc_edge.s"
	@echo "... src/gui/moc_glcolor.o"
	@echo "... src/gui/moc_glcolor.i"
	@echo "... src/gui/moc_glcolor.s"
	@echo "... src/gui/moc_glviewer.o"
	@echo "... src/gui/moc_glviewer.i"
	@echo "... src/gui/moc_glviewer.s"
	@echo "... src/gui/moc_mesh.o"
	@echo "... src/gui/moc_mesh.i"
	@echo "... src/gui/moc_mesh.s"
	@echo "... src/gui/moc_triangle.o"
	@echo "... src/gui/moc_triangle.i"
	@echo "... src/gui/moc_triangle.s"
	@echo "... src/gui/moc_vec3D.o"
	@echo "... src/gui/moc_vec3D.i"
	@echo "... src/gui/moc_vec3D.s"
	@echo "... src/gui/moc_vertex.o"
	@echo "... src/gui/moc_vertex.i"
	@echo "... src/gui/moc_vertex.s"
	@echo "... src/gui/moc_window.o"
	@echo "... src/gui/moc_window.i"
	@echo "... src/gui/moc_window.s"
	@echo "... src/gui/triangle.o"
	@echo "... src/gui/triangle.i"
	@echo "... src/gui/triangle.s"
	@echo "... src/gui/vertex.o"
	@echo "... src/gui/vertex.i"
	@echo "... src/gui/vertex.s"
	@echo "... src/gui/window.o"
	@echo "... src/gui/window.i"
	@echo "... src/gui/window.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
