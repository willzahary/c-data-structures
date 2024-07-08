cmake_minimum_required(VERSION 3.13)
project(c_data_structures)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/main.cpp
        src/lists/array.cpp)

set(TEST_FILES
        test/lists/array_test.cpp)

add_executable(c_data_structures ${SOURCE_FILES})
add_executable(tests ${TEST_FILES})

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.4.0
)

FetchContent_MakeAvailable(Catch2)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(tests)