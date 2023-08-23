project(example)

add_executable(example example.cpp random_generator/generator.cpp)

target_link_libraries(example PRIVATE curves-lib)