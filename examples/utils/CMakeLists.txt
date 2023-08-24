project(example-utils-lib)

add_library(example-utils-lib STATIC utils.cpp)

target_link_libraries(example-utils-lib PRIVATE curves-lib)