include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
    FIND_PACKAGE_ARGS NAMES "GTest GoogleTest googletest"
    EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(googletest)

add_executable(tests CLIUserInterfaceTest.cpp SummarizeSequenceTest.cpp ControllerTest.cpp)
target_link_libraries(tests PRIVATE GTest::gmock GTest::gtest_main implementation)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

include(GoogleTest)
gtest_discover_tests(tests)
