if(DEFINED CACHE{FORMATTER_PATH} AND NOT IS_EXECUTABLE ${FORMATTER_PATH})
unset(FORMATTER_PATH CACHE)
endif()

find_program(FORMATTER_PATH clang-format)

if(NOT FORMATTER_PATH)
message(WARNING "clang-formatter is not found on the system")
endif()

function(FORMAT_DIR)
foreach(LOCATION ${ARGV})
    file(GLOB_RECURSE FILES
    LIST_DIRECTORIES false 
    "${LOCATION}/*.cpp"
    "${LOCATION}/*.hpp")

    list(APPEND FILES_TO_FORMAT ${FILES})
endforeach()

    add_custom_target(format 
    COMMAND ${FORMATTER_PATH} -i ${FILES_TO_FORMAT} --style=Google
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Formatting ${FILES_TO_FORMAT}")
endfunction()

