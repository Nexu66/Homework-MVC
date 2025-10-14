add_executable(main main.cpp Controller.cpp SummarizeSequence.cpp CLIUserInterface.cpp)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)