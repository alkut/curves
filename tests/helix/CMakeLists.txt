project(helix-test)

add_executable(helix-test helix.cpp)

target_link_libraries(helix-test
        PRIVATE GTest::gtest GTest::gtest_main
        curves-lib)

add_test(
        NAME helix
        COMMAND helix-test)