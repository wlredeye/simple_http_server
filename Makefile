# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/sf_src/mailru/simple_http_server/simple_http_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/sf_src/mailru/simple_http_server/simple_http_server

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
	$(CMAKE_COMMAND) -E cmake_progress_start /media/sf_src/mailru/simple_http_server/simple_http_server/CMakeFiles /media/sf_src/mailru/simple_http_server/simple_http_server/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /media/sf_src/mailru/simple_http_server/simple_http_server/CMakeFiles 0
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
# Target rules for targets named final

# Build rule for target.
final: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 final
.PHONY : final

# fast build rule for target.
final/fast:
	$(MAKE) -f CMakeFiles/final.dir/build.make CMakeFiles/final.dir/build
.PHONY : final/fast

TCPServer.o: TCPServer.cpp.o
.PHONY : TCPServer.o

# target to build an object file
TCPServer.cpp.o:
	$(MAKE) -f CMakeFiles/final.dir/build.make CMakeFiles/final.dir/TCPServer.cpp.o
.PHONY : TCPServer.cpp.o

TCPServer.i: TCPServer.cpp.i
.PHONY : TCPServer.i

# target to preprocess a source file
TCPServer.cpp.i:
	$(MAKE) -f CMakeFiles/final.dir/build.make CMakeFiles/final.dir/TCPServer.cpp.i
.PHONY : TCPServer.cpp.i

TCPServer.s: TCPServer.cpp.s
.PHONY : TCPServer.s

# target to generate assembly for a file
TCPServer.cpp.s:
	$(MAKE) -f CMakeFiles/final.dir/build.make CMakeFiles/final.dir/TCPServer.cpp.s
.PHONY : TCPServer.cpp.s

ThreadPool.o: ThreadPool.cpp.o
.PHONY : ThreadPool.o

# target to build an object file
ThreadPool.cpp.o:
	$(MAKE) -f CMakeFiles/final.dir/build.make CMakeFiles/final.dir/ThreadPool.cpp.o
.PHONY : ThreadPool.cpp.o

ThreadPool.i: ThreadPool.cpp.i
.PHONY : ThreadPool.i

# target to preprocess a source file
ThreadPool.cpp.i:
	$(MAKE) -f CMakeFiles/final.dir/build.make CMakeFiles/final.dir/ThreadPool.cpp.i
.PHONY : ThreadPool.cpp.i

ThreadPool.s: ThreadPool.cpp.s
.PHONY : ThreadPool.s

# target to generate assembly for a file
ThreadPool.cpp.s:
	$(MAKE) -f CMakeFiles/final.dir/build.make CMakeFiles/final.dir/ThreadPool.cpp.s
.PHONY : ThreadPool.cpp.s

Worker.o: Worker.cpp.o
.PHONY : Worker.o

# target to build an object file
Worker.cpp.o:
	$(MAKE) -f CMakeFiles/final.dir/build.make CMakeFiles/final.dir/Worker.cpp.o
.PHONY : Worker.cpp.o

Worker.i: Worker.cpp.i
.PHONY : Worker.i

# target to preprocess a source file
Worker.cpp.i:
	$(MAKE) -f CMakeFiles/final.dir/build.make CMakeFiles/final.dir/Worker.cpp.i
.PHONY : Worker.cpp.i

Worker.s: Worker.cpp.s
.PHONY : Worker.s

# target to generate assembly for a file
Worker.cpp.s:
	$(MAKE) -f CMakeFiles/final.dir/build.make CMakeFiles/final.dir/Worker.cpp.s
.PHONY : Worker.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/final.dir/build.make CMakeFiles/final.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/final.dir/build.make CMakeFiles/final.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/final.dir/build.make CMakeFiles/final.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... final"
	@echo "... rebuild_cache"
	@echo "... TCPServer.o"
	@echo "... TCPServer.i"
	@echo "... TCPServer.s"
	@echo "... ThreadPool.o"
	@echo "... ThreadPool.i"
	@echo "... ThreadPool.s"
	@echo "... Worker.o"
	@echo "... Worker.i"
	@echo "... Worker.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

