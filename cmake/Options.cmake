option(BUILD_TESTS "googletest required - may fetch" ON)
option(BUILD_EXAMPLES "build examples" ON)

if ( BUILD_TESTS )
    enable_testing()
    include(cmake/AddGTest.cmake)
    add_subdirectory(tests)
endif ()

option(ENABLE_CCACHE "enable Ccache" OFF)

if ( ENABLE_CCACHE )
    include(cmake/EnableCcache.cmake)
endif ()

option(BUILD_SHARED "build shared lib instead of static" ON)

option(RUN_ON_CI "used for ci/cd" OFF)