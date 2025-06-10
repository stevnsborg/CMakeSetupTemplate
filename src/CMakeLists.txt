# Define the source files
# CMake adds all .cpp files in the src directory to the MY_SOURCES variable. This can then be added to the executable.
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "*.cpp")
#target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC GLFW_INCLUDE) # something with openGL??

message(STATUS "Adding math library to project ${CMAKE_SOURCE_DIR}")
add_library(MainDll SHARED ${MY_SOURCES})
target_include_directories(MainDll PUBLIC "${CMAKE_SOURCE_DIR}/include" PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
#target_precompile_headers(MainDll PRIVATE "${CMAKE_SOURCE_DIR}/include/pch.h")
target_compile_definitions(MainDll PRIVATE MYLIB_EXPORTS)
# Optionally link third-party libraries from libs/
# target_link_libraries(mylib PRIVATE some_library)
