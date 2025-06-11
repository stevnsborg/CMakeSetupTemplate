# link to the template used for the project
# https://github.com/stevnsborg/CMakeSetupTemplate
# Version 1.2.0

# set the CMake minimum version required
cmake_minimum_required(VERSION "3.12.0")	# The most recent version is 4.0 (but too recent to commit general inclusion)

# ===========================
# OPTIMISATIONS
# ===========================
#
#if (${PRODUCTION_BUILD} MATCHES ON)
#	set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
#else()
#	set(CMAKE_INTERPROCEDURAL_OPTIMIZATION FALSE)
#endif()
#

# if using the VS compiler 
if (MSVC)
add_compile_options(/arch:AVX2) # Enable AVX2 instructions (SIMD optimizations are ensured)
endif()

# ===========================
# CONTROL THE BUILD PROCESS
# ===========================

file(READ "config.txt" CONFIG_CONTENTS)

# Project Name
string(REGEX MATCH "PROJECT_NAME=([^\n]*)" _ ${CONFIG_CONTENTS})
string(REGEX REPLACE "PROJECT_NAME=" "" PROJECT_NAME "${CMAKE_MATCH_0}")

# Version number
string(REGEX MATCH "LIBRARY_NAME=([^\n]*)" _ ${CONFIG_CONTENTS})
string(REGEX REPLACE "LIBRARY_NAME=" "" LIBRARY_NAME "${CMAKE_MATCH_0}")

# .dll module Name
string(REGEX MATCH "PROJECT_VERSION=([^\n]*)" _ ${CONFIG_CONTENTS})
string(REGEX REPLACE "PROJECT_VERSION=" "" PROJECT_VERSION "${CMAKE_MATCH_0}")

message(STATUS "Compiling DLL: ${LIBRARY_NAME} (v${PROJECT_VERSION})")

# ===========================
# CONTROL THE BUILD PROCESS
# ===========================

# Custom toggles # [ON/OFF] manual switch with default values:
option(PRODUCTION_BUILD		" "		OFF) 
option(BUILD_SHARED_LIBS	" "		ON) 
option(ENABLE_TESTING		" "		ON)
option(BUILD_DOCS			" "		ON)

project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})	# The name of the project

# Set the C++ standard to C++17 & (optional) If the version is not supported FAIL the build
set(CMAKE_CXX_STANDARD 17)		
set(CMAKE_CXX_STANDARD_REQUIRED ON)		
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Output directories (bundle all output files in the build/bin folder)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include custom CMake modules if needed
#list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")

# ===========================
# CODE COVERAGE ASSESSMENT
# ===========================

option(CODE_COVERAGE "Enable coverage reporting" OFF)
set(CODE_COVERAGE ON)

message(STATUS "Coverage: ${CODE_COVERAGE}")

if(CODE_COVERAGE)
message(STATUS "VAL: ${CMAKE_CXX_COMPILER_ID}")
	if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
	message(STATUS "Code coverage enabled")
	#        add_compile_options(--coverage -O0 -g)
	#        add_link_options(--coverage)
	else()
	message(STATUS "Code coverage only supported with GCC or Clang")
	endif()
endif()

# Add subdirectories in build order
add_subdirectory("src")
add_subdirectory("tests")
add_subdirectory("demo")

enable_testing()

# ===========================
# SETUP DOCUMENTATION GENERATION
# ===========================

# Define Doxygen binary URL and path
set(DOXYGEN_ZIP_URL "https://github.com/doxygen/doxygen/releases/download/Release_1_14_0/doxygen-1.14.0.windows.x64.bin.zip")
set(DOXYGEN_ZIP ${CMAKE_BINARY_DIR}/doxygen.zip)
set(DOXYGEN_DIR ${CMAKE_BINARY_DIR}/doxygen-bin)
set(DOXYGEN_EXE ${CMAKE_BINARY_DIR}/doxygen.exe)

# Debug messages for paths
message(STATUS "BIN DIR : " ${CMAKE_BINARY_DIR})
message(STATUS "DOX DIR : " ${DOXYGEN_DIR})
message(STATUS "Using doxygen from: ${DOXYGEN_EXE}")

# Only download Doxygen if it does not exist
if(NOT EXISTS ${DOXYGEN_EXE})
	# Download and unzip Doxygen binary
	file(DOWNLOAD ${DOXYGEN_ZIP_URL} ${DOXYGEN_ZIP} SHOW_PROGRESS)
	execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf ${DOXYGEN_ZIP} WORKING_DIRECTORY ${CMAKE_BINARY_DIR} RESULT_VARIABLE unzip_result)

	if(NOT unzip_result EQUAL 0)
		message(FATAL_ERROR "Failed to unzip Doxygen")
	endif()
endif()

# Configure Doxyfile with actual paths
set(DOXYFILE_CONFIG ${CMAKE_BINARY_DIR}/Doxyfile.txt)
configure_file(${CMAKE_SOURCE_DIR}/docs/Doxyfile.in ${DOXYFILE_CONFIG} @ONLY)

# Add documentation target
add_custom_command(
	OUTPUT ${CMAKE_BINARY_DIR}/docs/html/index.html 
	COMMAND ${DOXYGEN_EXE} ${DOXYFILE_CONFIG} 
	DEPENDS ${DOXYFILE_CONFIG} 
	COMMENT "Generating API documentation with downloaded Doxygen"
	VERBATIM
)

# Explicit shell command to generate documentation
add_custom_target(doc DEPENDS ${CMAKE_BINARY_DIR}/docs/html/index.html)
message(STATUS "Source Dir : " ${CMAKE_SOURCE_DIR})



# ===========================
# LANGUAGE CONFIGURATION
# ===========================

# Linking the runtime statically
# This is a workaround for the issue with the static runtime library
#set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
#set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")




# Export toggles to use in the program (NOTE: These are passed as STRINGS! NOT BOOLEAN)
# THESE DO NOT WORK HERE! A LINKING 
#add_definitions(-DPRODUCTION_BUILD=${PRODUCTION_BUILD})
#add_definitions(-DENABLE_TESTING=${ENABLE_TESTING})


# STATUS MESSAGES
#message(STATUS "Starting Build:")
#message(STATUS "C++ ${CMAKE_CXX_STANDARD} & PRODUCTION_BUILD is ${PRODUCTION_BUILD}")



#===========================
# CREATE THE PROJECT
#===========================

#list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/.cmake")

	

#add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/libs/Catch2") # [TEST LIB] downloaded/cloned from https://github.com/catchorg/Catch2/tree/devel

# Define a constant for the C++ project
# The macro "RESOURCES_PATH" can be used within the program to point to an absoulte path for the resourse
# This will have the type of const char* and can be used in the program as a string
#if(${PRODUCTION_BUILD} MATCHES ON)
#	message(STATUS "Building in production mode")
#	# Set up the asset path to be relative
#	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="./resources/")
#	# Remove the debug symbols
#	# This variable can also be accessed inside the program to e.g. not open a console window if running producion code
#	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC PRODUCTION_BUILD=1)
#
#else()
#	message(STATUS "Building in development mode")
#	# Set up the asset path to be absolute
#	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")
#endif()
#
## if useing the VS compiler ...
#if (MSVC)
#	# (optional) Stops VS from complaining about the use of unsafe functions
#	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC _CRT_SECURE_NO_WARNINGS)
#	# This variable can also be accessed inside the program to e.g. not open a console window if running producion code
#	#set_target_properties("${CMAKE_PROJECT_NAME}" PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#endif()



#===========================
# ENABLE TESTING FOR THE PROJECT
#===========================
#
#if(${ENABLE_TESTING})
#    #add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tests")
#	add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/libs/Catch2")
#	message(STATUS "Adding math_test library to project ${CMAKE_CURRENT_SOURCE_DIR}")
#	target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
#	#include(CTest)
#	#include(Catch)
#	#catch_discover_tests(${PROJECT_NAME})
#	message(STATUS "Testing Included")
#endif()


# ===========================
# LINKING LIBRARIES 
# ===========================

# Automatically add all third party external packages to the project
#file(GLOB CHILD_LIBS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/libs/*")
#foreach(lib_dir ${CHILD_LIBS})
#    if(IS_DIRECTORY ${lib_dir})
#		get_filename_component(lib_name ${lib_dir} NAME)
#		message(STATUS "Adding subdirectory: ${lib_name} @ ${lib_dir}")
#        add_subdirectory(${lib_dir})
#		target_link_libraries(${PROJECT_NAME} PRIVATE ${lib_name})
#    endif()
#endforeach()
#
# Add them explicitely
# add_subdirectory("./libs/<NAME>") # [TEST LIB] downloaded/cloned from https://github.com/catchorg/Catch2/tree/devel
# target_link_libraries(${PROJECT_NAME} PRIVATE <NAME>)

