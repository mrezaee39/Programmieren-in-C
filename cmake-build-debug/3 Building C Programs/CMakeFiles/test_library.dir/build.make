# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\programming-c-sose-21

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\programming-c-sose-21\cmake-build-debug

# Include any dependencies generated for this target.
include "3 Building C Programs\CMakeFiles\test_library.dir\depend.make"

# Include the progress variables for this target.
include "3 Building C Programs\CMakeFiles\test_library.dir\progress.make"

# Include the compile flags for this target's objects.
include "3 Building C Programs\CMakeFiles\test_library.dir\flags.make"

"3 Building C Programs\CMakeFiles\test_library.dir\main.c.obj": "3 Building C Programs\CMakeFiles\test_library.dir\flags.make"
"3 Building C Programs\CMakeFiles\test_library.dir\main.c.obj": "..\3 Building C Programs\main.c"
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\programming-c-sose-21\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object 3 Building C Programs/CMakeFiles/test_library.dir/main.c.obj"
	cd "E:\programming-c-sose-21\cmake-build-debug\3 Building C Programs"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\test_library.dir\main.c.obj /FdCMakeFiles\test_library.dir\test_library.pdb /FS -c "E:\programming-c-sose-21\3 Building C Programs\main.c"
<<
	cd E:\programming-c-sose-21\cmake-build-debug

"3 Building C Programs\CMakeFiles\test_library.dir\main.c.i": cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_library.dir/main.c.i"
	cd "E:\programming-c-sose-21\cmake-build-debug\3 Building C Programs"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\test_library.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "E:\programming-c-sose-21\3 Building C Programs\main.c"
<<
	cd E:\programming-c-sose-21\cmake-build-debug

"3 Building C Programs\CMakeFiles\test_library.dir\main.c.s": cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_library.dir/main.c.s"
	cd "E:\programming-c-sose-21\cmake-build-debug\3 Building C Programs"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\test_library.dir\main.c.s /c "E:\programming-c-sose-21\3 Building C Programs\main.c"
<<
	cd E:\programming-c-sose-21\cmake-build-debug

"3 Building C Programs\CMakeFiles\test_library.dir\test.c.obj": "3 Building C Programs\CMakeFiles\test_library.dir\flags.make"
"3 Building C Programs\CMakeFiles\test_library.dir\test.c.obj": "..\3 Building C Programs\test.c"
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\programming-c-sose-21\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object 3 Building C Programs/CMakeFiles/test_library.dir/test.c.obj"
	cd "E:\programming-c-sose-21\cmake-build-debug\3 Building C Programs"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\test_library.dir\test.c.obj /FdCMakeFiles\test_library.dir\test_library.pdb /FS -c "E:\programming-c-sose-21\3 Building C Programs\test.c"
<<
	cd E:\programming-c-sose-21\cmake-build-debug

"3 Building C Programs\CMakeFiles\test_library.dir\test.c.i": cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_library.dir/test.c.i"
	cd "E:\programming-c-sose-21\cmake-build-debug\3 Building C Programs"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\test_library.dir\test.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "E:\programming-c-sose-21\3 Building C Programs\test.c"
<<
	cd E:\programming-c-sose-21\cmake-build-debug

"3 Building C Programs\CMakeFiles\test_library.dir\test.c.s": cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_library.dir/test.c.s"
	cd "E:\programming-c-sose-21\cmake-build-debug\3 Building C Programs"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\test_library.dir\test.c.s /c "E:\programming-c-sose-21\3 Building C Programs\test.c"
<<
	cd E:\programming-c-sose-21\cmake-build-debug

"3 Building C Programs\CMakeFiles\test_library.dir\fibonacci_test.c.obj": "3 Building C Programs\CMakeFiles\test_library.dir\flags.make"
"3 Building C Programs\CMakeFiles\test_library.dir\fibonacci_test.c.obj": "..\3 Building C Programs\fibonacci_test.c"
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\programming-c-sose-21\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object 3 Building C Programs/CMakeFiles/test_library.dir/fibonacci_test.c.obj"
	cd "E:\programming-c-sose-21\cmake-build-debug\3 Building C Programs"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\test_library.dir\fibonacci_test.c.obj /FdCMakeFiles\test_library.dir\test_library.pdb /FS -c "E:\programming-c-sose-21\3 Building C Programs\fibonacci_test.c"
<<
	cd E:\programming-c-sose-21\cmake-build-debug

"3 Building C Programs\CMakeFiles\test_library.dir\fibonacci_test.c.i": cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_library.dir/fibonacci_test.c.i"
	cd "E:\programming-c-sose-21\cmake-build-debug\3 Building C Programs"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\test_library.dir\fibonacci_test.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "E:\programming-c-sose-21\3 Building C Programs\fibonacci_test.c"
<<
	cd E:\programming-c-sose-21\cmake-build-debug

"3 Building C Programs\CMakeFiles\test_library.dir\fibonacci_test.c.s": cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_library.dir/fibonacci_test.c.s"
	cd "E:\programming-c-sose-21\cmake-build-debug\3 Building C Programs"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\test_library.dir\fibonacci_test.c.s /c "E:\programming-c-sose-21\3 Building C Programs\fibonacci_test.c"
<<
	cd E:\programming-c-sose-21\cmake-build-debug

# Object files for target test_library
test_library_OBJECTS = \
"CMakeFiles\test_library.dir\main.c.obj" \
"CMakeFiles\test_library.dir\test.c.obj" \
"CMakeFiles\test_library.dir\fibonacci_test.c.obj"

# External object files for target test_library
test_library_EXTERNAL_OBJECTS =

"3 Building C Programs\test_library.lib": "3 Building C Programs\CMakeFiles\test_library.dir\main.c.obj"
"3 Building C Programs\test_library.lib": "3 Building C Programs\CMakeFiles\test_library.dir\test.c.obj"
"3 Building C Programs\test_library.lib": "3 Building C Programs\CMakeFiles\test_library.dir\fibonacci_test.c.obj"
"3 Building C Programs\test_library.lib": "3 Building C Programs\CMakeFiles\test_library.dir\build.make"
"3 Building C Programs\test_library.lib": "3 Building C Programs\CMakeFiles\test_library.dir\objects1.rsp"
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\programming-c-sose-21\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library test_library.lib"
	cd "E:\programming-c-sose-21\cmake-build-debug\3 Building C Programs"
	$(CMAKE_COMMAND) -P CMakeFiles\test_library.dir\cmake_clean_target.cmake
	cd E:\programming-c-sose-21\cmake-build-debug
	cd "E:\programming-c-sose-21\cmake-build-debug\3 Building C Programs"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\lib.exe /nologo /machine:X86 /out:test_library.lib @CMakeFiles\test_library.dir\objects1.rsp 
	cd E:\programming-c-sose-21\cmake-build-debug

# Rule to build all files generated by this target.
"3 Building C Programs\CMakeFiles\test_library.dir\build": "3 Building C Programs\test_library.lib"

.PHONY : "3 Building C Programs\CMakeFiles\test_library.dir\build"

"3 Building C Programs\CMakeFiles\test_library.dir\clean":
	cd "E:\programming-c-sose-21\cmake-build-debug\3 Building C Programs"
	$(CMAKE_COMMAND) -P CMakeFiles\test_library.dir\cmake_clean.cmake
	cd E:\programming-c-sose-21\cmake-build-debug
.PHONY : "3 Building C Programs\CMakeFiles\test_library.dir\clean"

"3 Building C Programs\CMakeFiles\test_library.dir\depend":
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" E:\programming-c-sose-21 "E:\programming-c-sose-21\3 Building C Programs" E:\programming-c-sose-21\cmake-build-debug "E:\programming-c-sose-21\cmake-build-debug\3 Building C Programs" "E:\programming-c-sose-21\cmake-build-debug\3 Building C Programs\CMakeFiles\test_library.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : "3 Building C Programs\CMakeFiles\test_library.dir\depend"

