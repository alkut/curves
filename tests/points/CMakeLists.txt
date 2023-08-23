project(point-test)

add_executable(point-test point.cpp)

target_link_libraries(point-test PRIVATE GTest::gtest GTest::gtest_main)

add_test(
        NAME point
        COMMAND point-test)