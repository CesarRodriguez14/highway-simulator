include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
    ${PROJECT_NAME}_test
    hello_test.cpp
    highway_test.cpp
    ../inc/highway.cpp
)

target_include_directories(
    ${PROJECT_NAME}_test
    PRIVATE
    ../inc
)

target_link_libraries(
    ${PROJECT_NAME}_test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)