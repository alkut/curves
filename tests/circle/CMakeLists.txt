project(circle-test)

add_executable(circle-test circle.cpp)

target_link_libraries(circle-test
        PRIVATE GTest::gtest GTest::gtest_main
        curves-lib)

add_test(
        NAME circle
        COMMAND circle-test)
