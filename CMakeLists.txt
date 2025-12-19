cmake_minimum_required(VERSION 3.10)
project(Octal)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

find_package(fmt REQUIRED)
add_library(array INTERFACE)
target_include_directories(array INTERFACE ${CMAKE_SOURCE_DIR})
add_library(octal octal.cpp)
target_link_libraries(octal PUBLIC array)
target_include_directories(octal PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE octal gtest_main)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE octal fmt::fmt)



gtest_discover_tests(tests)

