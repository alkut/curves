project(summator-lib)

add_library(summator-lib STATIC
        naive/naive_summator.cpp
        openMP/openMP_summator.cpp
        threads/threads_summator.cpp
        execution_policy/execution_policy_summator.cpp)

target_link_libraries(summator-lib PRIVATE curves-lib)

if (BUILD_TESTS)

    project(summator-test)

    add_executable(summator-test tests/summators.cpp)

    target_link_libraries(summator-test PRIVATE
            GTest::gtest GTest::gtest_main
            curves-lib
            summator-lib
            generator-lib)

    add_test(
            NAME summator
            COMMAND summator-test)

endif ()