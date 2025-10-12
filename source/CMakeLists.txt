add_executable(main main.cpp Controller.cpp View.cpp Module.cpp)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)