# link to the template used for the project
# https://github.com/stevnsborg/CMakeSetupTemplate
# Version 1.1.0

# set the CMake minimum version required
cmake_minimum_required(VERSION "3.29.0")
set(CMAKE_CXX_STANDARD 17) # Set the C++ standard to C++17

# ===========================
# CONTROL THE BUILD PROCESS
# ===========================
set(PRODUCTION_BUILD OFF CACHE BOOL "Compiling for production : " FORCE) # [ON/OFF] manual switch 
add_definitions(-D PRODUCTION_BUILD=${PRODUCTION_BUILD})

# Linking the runtime statically
# This is a workaround for the issue with the static runtime library
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")

if (PRODUCTION_BUILD)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION FALSE)
endif()

# if useing the VS compiler ...
if (MSVC)
add_compile_options(/arch:AVX2) # Enable AVX2 instructions (SIMD optimizations are ensured)
endif()

#===========================
# CREATE THE PROJECT
#===========================
project(ProjectName)

# Force to NOT be build as shared libraries
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

# Add all third party external packages
add_subdirectory("libs/Catch2") # [TEST LIB] downloaded/cloned from https://github.com/catchorg/Catch2/tree/devel

# Define the source files
# CMake adds all .cpp files in the src directory to the MY_SOURCES variable. This can then be added to the executable.
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME} "${MY_SOURCES}")
#target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC GLFW_INCLUDE) # something with openGL??


# Define a constant for the C++ project
# The macro "RESOURCES_PATH" can be used within the program to point to an absoulte path for the resourse
# This will have the type of const char* and can be used in the program as a string
if(PRODUCTION_BUILD)
	# Set up the asset path to be relative
	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="./resources/")
	# Remove the debug symbols
	# This variable can also be accessed inside the program to e.g. not open a console window if running producion code
	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC PRODUCTION_BUILD=1)

else()
	# Set up the asset path to be absolute
	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")
endif()

# if useing the VS compiler ...
if (MSVC)
	# (optional) Stops VS from complaining about the use of unsafe functions
	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC _CRT_SECURE_NO_WARNINGS)
	# This variable can also be accessed inside the program to e.g. not open a console window if running producion code
	#set_target_properties("${CMAKE_PROJECT_NAME}" PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif()


#===========================
# ENABLE TESTING FOR THE PROJECT
#===========================
#enable_testing()
#
## Gather all test source files
#file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp")
#
## Create the test executable
#add_executable(UnitTests "${TEST_SOURCES}")
#
## Link Catch2 and your main project (if needed)
#target_link_libraries(UnitTests PRIVATE Catch2::Catch2WithMain ${PROJECT_NAME})
#
## Add include directories if needed
#target_include_directories(UnitTests PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
#
## Register the tests with CTest
#include(CTest)
#include(Catch)
#catch_discover_tests(${PROJECT_NAME})




# Add the tests directory
# target_include_directories(Main PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/tests/")

# target_link_libraries(Main PRIVATE Catch2)
#target_link_libraries(Main PRIVATE projectname)