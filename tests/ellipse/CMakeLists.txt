project(ellipse-test)

add_executable(ellipse-test ellipse.cpp)

target_link_libraries(ellipse-test
        PRIVATE GTest::gtest GTest::gtest_main
        curves-lib)

add_test(
        NAME ellipse
        COMMAND ellipse-test)