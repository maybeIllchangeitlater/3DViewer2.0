# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/susannel/3dviewer2/view

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug

# Include any dependencies generated for this target.
include CMakeFiles/gpt_help.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gpt_help.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gpt_help.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gpt_help.dir/flags.make

gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp: /Users/susannel/3dviewer2/shaders.qrc
gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp: CMakeFiles/gpt_help_autogen.dir/AutoRcc_shaders_54WNFGSGJX_Info.json
gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp: /Users/susannel/3dviewer2/resources/GeometryShader.txt
gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp: /Users/susannel/3dviewer2/resources/VertexShader.txt
gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp: /Users/susannel/3dviewer2/resources/VertexShaderCPU.txt
gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp: /Users/susannel/3dviewer2/resources/FragShader.txt
gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp: /usr/local/share/qt/libexec/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic RCC for ../shaders.qrc"
	/Applications/CMake.app/Contents/bin/cmake -E cmake_autorcc /Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles/gpt_help_autogen.dir/AutoRcc_shaders_54WNFGSGJX_Info.json Debug

CMakeFiles/gpt_help.dir/gpt_help_autogen/mocs_compilation.cpp.o: CMakeFiles/gpt_help.dir/flags.make
CMakeFiles/gpt_help.dir/gpt_help_autogen/mocs_compilation.cpp.o: gpt_help_autogen/mocs_compilation.cpp
CMakeFiles/gpt_help.dir/gpt_help_autogen/mocs_compilation.cpp.o: CMakeFiles/gpt_help.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/gpt_help.dir/gpt_help_autogen/mocs_compilation.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gpt_help.dir/gpt_help_autogen/mocs_compilation.cpp.o -MF CMakeFiles/gpt_help.dir/gpt_help_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/gpt_help.dir/gpt_help_autogen/mocs_compilation.cpp.o -c /Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/gpt_help_autogen/mocs_compilation.cpp

CMakeFiles/gpt_help.dir/gpt_help_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpt_help.dir/gpt_help_autogen/mocs_compilation.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/gpt_help_autogen/mocs_compilation.cpp > CMakeFiles/gpt_help.dir/gpt_help_autogen/mocs_compilation.cpp.i

CMakeFiles/gpt_help.dir/gpt_help_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpt_help.dir/gpt_help_autogen/mocs_compilation.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/gpt_help_autogen/mocs_compilation.cpp -o CMakeFiles/gpt_help.dir/gpt_help_autogen/mocs_compilation.cpp.s

CMakeFiles/gpt_help.dir/main.cc.o: CMakeFiles/gpt_help.dir/flags.make
CMakeFiles/gpt_help.dir/main.cc.o: /Users/susannel/3dviewer2/view/main.cc
CMakeFiles/gpt_help.dir/main.cc.o: CMakeFiles/gpt_help.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/gpt_help.dir/main.cc.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gpt_help.dir/main.cc.o -MF CMakeFiles/gpt_help.dir/main.cc.o.d -o CMakeFiles/gpt_help.dir/main.cc.o -c /Users/susannel/3dviewer2/view/main.cc

CMakeFiles/gpt_help.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpt_help.dir/main.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/susannel/3dviewer2/view/main.cc > CMakeFiles/gpt_help.dir/main.cc.i

CMakeFiles/gpt_help.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpt_help.dir/main.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/susannel/3dviewer2/view/main.cc -o CMakeFiles/gpt_help.dir/main.cc.s

CMakeFiles/gpt_help.dir/widget.cc.o: CMakeFiles/gpt_help.dir/flags.make
CMakeFiles/gpt_help.dir/widget.cc.o: /Users/susannel/3dviewer2/view/widget.cc
CMakeFiles/gpt_help.dir/widget.cc.o: CMakeFiles/gpt_help.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/gpt_help.dir/widget.cc.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gpt_help.dir/widget.cc.o -MF CMakeFiles/gpt_help.dir/widget.cc.o.d -o CMakeFiles/gpt_help.dir/widget.cc.o -c /Users/susannel/3dviewer2/view/widget.cc

CMakeFiles/gpt_help.dir/widget.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpt_help.dir/widget.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/susannel/3dviewer2/view/widget.cc > CMakeFiles/gpt_help.dir/widget.cc.i

CMakeFiles/gpt_help.dir/widget.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpt_help.dir/widget.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/susannel/3dviewer2/view/widget.cc -o CMakeFiles/gpt_help.dir/widget.cc.s

CMakeFiles/gpt_help.dir/mainwindow.cc.o: CMakeFiles/gpt_help.dir/flags.make
CMakeFiles/gpt_help.dir/mainwindow.cc.o: /Users/susannel/3dviewer2/view/mainwindow.cc
CMakeFiles/gpt_help.dir/mainwindow.cc.o: CMakeFiles/gpt_help.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/gpt_help.dir/mainwindow.cc.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gpt_help.dir/mainwindow.cc.o -MF CMakeFiles/gpt_help.dir/mainwindow.cc.o.d -o CMakeFiles/gpt_help.dir/mainwindow.cc.o -c /Users/susannel/3dviewer2/view/mainwindow.cc

CMakeFiles/gpt_help.dir/mainwindow.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpt_help.dir/mainwindow.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/susannel/3dviewer2/view/mainwindow.cc > CMakeFiles/gpt_help.dir/mainwindow.cc.i

CMakeFiles/gpt_help.dir/mainwindow.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpt_help.dir/mainwindow.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/susannel/3dviewer2/view/mainwindow.cc -o CMakeFiles/gpt_help.dir/mainwindow.cc.s

CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/parser.cc.o: CMakeFiles/gpt_help.dir/flags.make
CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/parser.cc.o: /Users/susannel/3dviewer2/model/parser.cc
CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/parser.cc.o: CMakeFiles/gpt_help.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/parser.cc.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/parser.cc.o -MF CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/parser.cc.o.d -o CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/parser.cc.o -c /Users/susannel/3dviewer2/model/parser.cc

CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/parser.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/parser.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/susannel/3dviewer2/model/parser.cc > CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/parser.cc.i

CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/parser.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/parser.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/susannel/3dviewer2/model/parser.cc -o CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/parser.cc.s

CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/model.cc.o: CMakeFiles/gpt_help.dir/flags.make
CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/model.cc.o: /Users/susannel/3dviewer2/model/model.cc
CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/model.cc.o: CMakeFiles/gpt_help.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/model.cc.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/model.cc.o -MF CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/model.cc.o.d -o CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/model.cc.o -c /Users/susannel/3dviewer2/model/model.cc

CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/model.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/model.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/susannel/3dviewer2/model/model.cc > CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/model.cc.i

CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/model.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/model.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/susannel/3dviewer2/model/model.cc -o CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/model.cc.s

CMakeFiles/gpt_help.dir/settings.cc.o: CMakeFiles/gpt_help.dir/flags.make
CMakeFiles/gpt_help.dir/settings.cc.o: /Users/susannel/3dviewer2/view/settings.cc
CMakeFiles/gpt_help.dir/settings.cc.o: CMakeFiles/gpt_help.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/gpt_help.dir/settings.cc.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gpt_help.dir/settings.cc.o -MF CMakeFiles/gpt_help.dir/settings.cc.o.d -o CMakeFiles/gpt_help.dir/settings.cc.o -c /Users/susannel/3dviewer2/view/settings.cc

CMakeFiles/gpt_help.dir/settings.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpt_help.dir/settings.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/susannel/3dviewer2/view/settings.cc > CMakeFiles/gpt_help.dir/settings.cc.i

CMakeFiles/gpt_help.dir/settings.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpt_help.dir/settings.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/susannel/3dviewer2/view/settings.cc -o CMakeFiles/gpt_help.dir/settings.cc.s

CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/OpenGLTransformation.cc.o: CMakeFiles/gpt_help.dir/flags.make
CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/OpenGLTransformation.cc.o: /Users/susannel/3dviewer2/model/OpenGLTransformation.cc
CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/OpenGLTransformation.cc.o: CMakeFiles/gpt_help.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/OpenGLTransformation.cc.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/OpenGLTransformation.cc.o -MF CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/OpenGLTransformation.cc.o.d -o CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/OpenGLTransformation.cc.o -c /Users/susannel/3dviewer2/model/OpenGLTransformation.cc

CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/OpenGLTransformation.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/OpenGLTransformation.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/susannel/3dviewer2/model/OpenGLTransformation.cc > CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/OpenGLTransformation.cc.i

CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/OpenGLTransformation.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/OpenGLTransformation.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/susannel/3dviewer2/model/OpenGLTransformation.cc -o CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/OpenGLTransformation.cc.s

CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/CPUTransformation.cc.o: CMakeFiles/gpt_help.dir/flags.make
CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/CPUTransformation.cc.o: /Users/susannel/3dviewer2/model/CPUTransformation.cc
CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/CPUTransformation.cc.o: CMakeFiles/gpt_help.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/CPUTransformation.cc.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/CPUTransformation.cc.o -MF CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/CPUTransformation.cc.o.d -o CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/CPUTransformation.cc.o -c /Users/susannel/3dviewer2/model/CPUTransformation.cc

CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/CPUTransformation.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/CPUTransformation.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/susannel/3dviewer2/model/CPUTransformation.cc > CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/CPUTransformation.cc.i

CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/CPUTransformation.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/CPUTransformation.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/susannel/3dviewer2/model/CPUTransformation.cc -o CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/CPUTransformation.cc.s

CMakeFiles/gpt_help.dir/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp.o: CMakeFiles/gpt_help.dir/flags.make
CMakeFiles/gpt_help.dir/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp.o: gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp
CMakeFiles/gpt_help.dir/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp.o: CMakeFiles/gpt_help.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/gpt_help.dir/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gpt_help.dir/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp.o -MF CMakeFiles/gpt_help.dir/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp.o.d -o CMakeFiles/gpt_help.dir/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp.o -c /Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp

CMakeFiles/gpt_help.dir/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpt_help.dir/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp > CMakeFiles/gpt_help.dir/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp.i

CMakeFiles/gpt_help.dir/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpt_help.dir/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp -o CMakeFiles/gpt_help.dir/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp.s

# Object files for target gpt_help
gpt_help_OBJECTS = \
"CMakeFiles/gpt_help.dir/gpt_help_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/gpt_help.dir/main.cc.o" \
"CMakeFiles/gpt_help.dir/widget.cc.o" \
"CMakeFiles/gpt_help.dir/mainwindow.cc.o" \
"CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/parser.cc.o" \
"CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/model.cc.o" \
"CMakeFiles/gpt_help.dir/settings.cc.o" \
"CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/OpenGLTransformation.cc.o" \
"CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/CPUTransformation.cc.o" \
"CMakeFiles/gpt_help.dir/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp.o"

# External object files for target gpt_help
gpt_help_EXTERNAL_OBJECTS =

gpt_help.app/Contents/MacOS/gpt_help: CMakeFiles/gpt_help.dir/gpt_help_autogen/mocs_compilation.cpp.o
gpt_help.app/Contents/MacOS/gpt_help: CMakeFiles/gpt_help.dir/main.cc.o
gpt_help.app/Contents/MacOS/gpt_help: CMakeFiles/gpt_help.dir/widget.cc.o
gpt_help.app/Contents/MacOS/gpt_help: CMakeFiles/gpt_help.dir/mainwindow.cc.o
gpt_help.app/Contents/MacOS/gpt_help: CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/parser.cc.o
gpt_help.app/Contents/MacOS/gpt_help: CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/model.cc.o
gpt_help.app/Contents/MacOS/gpt_help: CMakeFiles/gpt_help.dir/settings.cc.o
gpt_help.app/Contents/MacOS/gpt_help: CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/OpenGLTransformation.cc.o
gpt_help.app/Contents/MacOS/gpt_help: CMakeFiles/gpt_help.dir/Users/susannel/3dviewer2/model/CPUTransformation.cc.o
gpt_help.app/Contents/MacOS/gpt_help: CMakeFiles/gpt_help.dir/gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp.o
gpt_help.app/Contents/MacOS/gpt_help: CMakeFiles/gpt_help.dir/build.make
gpt_help.app/Contents/MacOS/gpt_help: /usr/local/lib/QtOpenGLWidgets.framework/Versions/A/QtOpenGLWidgets
gpt_help.app/Contents/MacOS/gpt_help: /usr/local/lib/QtWidgets.framework/Versions/A/QtWidgets
gpt_help.app/Contents/MacOS/gpt_help: /usr/local/lib/QtOpenGL.framework/Versions/A/QtOpenGL
gpt_help.app/Contents/MacOS/gpt_help: /usr/local/lib/QtGui.framework/Versions/A/QtGui
gpt_help.app/Contents/MacOS/gpt_help: /usr/local/lib/QtCore.framework/Versions/A/QtCore
gpt_help.app/Contents/MacOS/gpt_help: CMakeFiles/gpt_help.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable gpt_help.app/Contents/MacOS/gpt_help"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gpt_help.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gpt_help.dir/build: gpt_help.app/Contents/MacOS/gpt_help
.PHONY : CMakeFiles/gpt_help.dir/build

CMakeFiles/gpt_help.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gpt_help.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gpt_help.dir/clean

CMakeFiles/gpt_help.dir/depend: gpt_help_autogen/54WNFGSGJX/qrc_shaders.cpp
	cd /Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/susannel/3dviewer2/view /Users/susannel/3dviewer2/view /Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug /Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug /Users/susannel/3dviewer2/build-view-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles/gpt_help.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gpt_help.dir/depend

