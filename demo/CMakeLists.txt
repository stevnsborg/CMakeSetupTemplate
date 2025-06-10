file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "*.cpp")
add_executable(Demo ${MY_SOURCES})


message(STATUS "Demo sources: ${MY_SOURCES}")
message(STATUS "${CMAKE_SOURCE_DIR}/include")

target_include_directories(Demo PRIVATE "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(Demo PRIVATE MainDll)