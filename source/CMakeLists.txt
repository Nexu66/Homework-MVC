add_executable(main main.cpp )
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_library(implementation STATIC ControllerImpl.cpp SummarizeSequenceImpl.cpp CLIUserInterfaceImpl.cpp)
target_include_directories(implementation PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(main PRIVATE implementation)