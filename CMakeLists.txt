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

include_directories(${CMAKE_SOURCE_DIR}/include)

set(MAIN_SOURCE main.cpp)
set(TESTS_SOURCE tests.cpp)
set(LIB_SOURCES
    source/chararray.cpp
    source/octal.cpp
)

add_library(lib STATIC ${LIB_SOURCES})
target_include_directories(lib PUBLIC include)

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE lib gtest_main)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE lib fmt::fmt)


gtest_discover_tests(tests)

