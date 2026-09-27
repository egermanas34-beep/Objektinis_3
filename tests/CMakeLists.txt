set(SOURCES
    vector_tests.cpp
)

add_executable(VectorTest ${SOURCES})

target_include_directories(VectorTest PRIVATE
    ../include
)

target_link_libraries(VectorTest PRIVATE
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(VectorTest)