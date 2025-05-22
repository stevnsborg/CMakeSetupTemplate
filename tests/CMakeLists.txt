
include(AddCatch2)

# Adding all registered test .cpp files to a separate executable
# file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "math_test.cpp")
message(STATUS "Adding math_test library to project ${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(unit_tests "./mymath_test.cpp")

# Link the library added in the top-cmakelists.txt
target_link_libraries(unit_tests PRIVATE mymath Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(unit_tests)
