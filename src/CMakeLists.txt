# Define the source files
# CMake adds all .cpp files in the src directory to the MY_SOURCES variable. This can then be added to the executable.
# file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "math.cpp")
#target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC GLFW_INCLUDE) # something with openGL??

message(STATUS "Adding math library to project ${CMAKE_CURRENT_SOURCE_DIR}")
add_library(mymath "./mymath.cpp" "mymath.h")
target_include_directories(mymath PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")