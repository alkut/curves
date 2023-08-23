project(example)

add_subdirectory(random_generator)
add_subdirectory(summator)

add_executable(example example.cpp)

target_link_libraries(example PRIVATE curves-lib generator summator)