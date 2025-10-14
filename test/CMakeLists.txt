add_executable(tests ViewTest.cpp ModuleTest.cpp ControllerTest.cpp)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/include)