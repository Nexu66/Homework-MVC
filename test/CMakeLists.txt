include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
    FIND_PACKAGE_ARGS NAMES "GTest GoogleTest googletest"
)
FetchContent_MakeAvailable(googletest)

add_executable(tests CLIUserInterfaceTest.cpp SummarizeSequenceTest.cpp ControllerTest.cpp)
target_link_libraries(tests PRIVATE GTest::gmock GTest::gtest_main implementation)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_test(test ${CMAKE_BINARY_DIR}/test/tests)
