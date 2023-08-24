add_subdirectory(random_generator)
add_subdirectory(summator)
add_subdirectory(utils)

if (BUILD_EXAMPLES)

    project(example)

    add_executable(example example.cpp)

    target_link_libraries(example PRIVATE curves-lib generator-lib summator-lib example-utils-lib)

endif ()