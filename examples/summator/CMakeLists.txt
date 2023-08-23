project(summator)

project(summator-test)

set(SUMMATOR_SOURCES
        naive/naive_summator.cpp
        openMP/openMP_summator.cpp
        threads/threads_summator.cpp)

add_library(summator STATIC
        naive/naive_summator.cpp
        openMP/openMP_summator.cpp
        threads/threads_summator.cpp)

target_link_libraries(summator PRIVATE curves-lib)
