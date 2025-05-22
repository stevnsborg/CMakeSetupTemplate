# link to the template used for the project
# https://github.com/stevnsborg/CMakeSetupTemplate
# Version 1.2.0

# set the CMake minimum version required
cmake_minimum_required(VERSION "3.12.0")	# The most recent version is 4.0 (but too recent to commit general inclusion)

# ===========================
# LANGUAGE CONFIGURATION
# ===========================
#set(CMAKE_CXX_STANDARD 17)					# Set the C++ standard to C++17
#set(CMAKE_CXX_STANDARD_REQUIRED ON)			# (optional) If the version is not supported FAIL the build

# Linking the runtime statically
# This is a workaround for the issue with the static runtime library
#set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
#set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")

# ===========================
# CONTROL THE BUILD PROCESS
# ===========================

# Custom toggles # [ON/OFF] manual switch:
#option(PRODUCTION_BUILD		" "		OFF) 
#option(BUILD_SHARED_LIBS	" "		ON) 
#option(ENABLE_TESTING		" "		ON)
#option(BUILD_DOCS			" "		ON)


# Export toggles to use in the program (NOTE: These are passed as STRINGS! NOT BOOLEAN)
#add_definitions(-DPRODUCTION_BUILD=${PRODUCTION_BUILD})
#add_definitions(-DENABLE_TESTING=${ENABLE_TESTING})


# STATUS MESSAGES
#message(STATUS "Starting Build:")
#message(STATUS "C++ ${CMAKE_CXX_STANDARD} & PRODUCTION_BUILD is ${PRODUCTION_BUILD}")

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
## if useing the VS compiler ...
#if (MSVC)
#add_compile_options(/arch:AVX2) # Enable AVX2 instructions (SIMD optimizations are ensured)
#endif()
#

#===========================
# CREATE THE PROJECT
#===========================
project(MainBuild VERSION 0.0.1)	# The name of the project

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/.cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/libs/Catch2") # [TEST LIB] downloaded/cloned from https://github.com/catchorg/Catch2/tree/devel
add_subdirectory("src")
add_subdirectory("demo")
add_subdirectory("tests")

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

enable_testing()

message(STATUS "Building : " ${PROJECT_NAME})

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



# ==========================
# CUSTOM CMAKE CONFIGURATION
# ==========================







#===========================
# ENABLE TESTING FOR THE PROJECT
#===========================
#
#if(${ENABLE_TESTING})
#    enable_testing()
#    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tests")
#	add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/libs/Catch2")
#	target_link_libraries(${PROJECT_NAME} PRIVATE math Catch2::Catch2WithMain)
#	include(CTest)
#	include(Catch)
#	catch_discover_tests(${PROJECT_NAME})
#	message(STATUS "Testing Included")
#endif()



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