add_executable(main main.cpp ControllerImpl.cpp SummarizeSequenceImpl.cpp CLIUserInterfaceImpl.cpp)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)