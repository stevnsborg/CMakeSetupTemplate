# Include source repo for the unit tests 
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Catch2")

# Adding all registered test .cpp files to a separate executable
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/files/*.cpp")
message(STATUS "Adding math_test library to project ${CMAKE_CURRENT_SOURCE_DIR}")

# Adding all registered test .cpp files to a separate executable
add_executable(UnitTests ${MY_SOURCES})

# Link the library added in the top-cmakelists.txt
target_include_directories(UnitTests PRIVATE "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(UnitTests PRIVATE ${LIBRARY_NAME} Catch2::Catch2WithMain)

# run the three Catch2 macro functions
include(CTest)
include(Catch)
catch_discover_tests(UnitTests)