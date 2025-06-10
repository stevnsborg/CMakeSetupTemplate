
#include(AddCatch2)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Catch2")

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/files/*.cpp")
# Adding all registered test .cpp files to a separate executable
# file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "math_test.cpp")
message(STATUS "Adding math_test library to project ${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(UnitTests ${MY_SOURCES})

# Link the library added in the top-cmakelists.txt
target_include_directories(UnitTests PRIVATE "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(UnitTests PRIVATE MainDll Catch2::Catch2WithMain)

#include(CTest)
#include(Catch)
#catch_discover_tests(UnitTests)
