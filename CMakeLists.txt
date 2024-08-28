cmake_minimum_required(VERSION 3.20)
project(health_calculator)

set(CMAKE_CXX_STANDARD 20)

add_library(calculate_health calculate_health.cpp)

add_executable(health_calculator main.cpp)
target_link_libraries(health_calculator calculate_health)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_calculate_health tests/test_calculate_health.cpp)
target_link_libraries(
        test_calculate_health
        GTest::gtest_main
        calculate_health
)

include(GoogleTest)
gtest_discover_tests(test_calculate_health)
