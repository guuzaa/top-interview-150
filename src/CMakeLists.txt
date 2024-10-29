add_subdirectory(array)
add_subdirectory(string)
add_subdirectory(twopointers)
add_subdirectory(slidingwindow)
add_subdirectory(matrix)
add_subdirectory(hashmap)

# TODO support dynamic library
add_library(${PROJECT_NAME} STATIC ${ALL_OBJECT_FILES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
set(ALL_OBJECTS ${ALL_OBJECTS} PARENT_SCOPE)

add_subdirectory(bin)

add_custom_target(
    unit-tests
    COMMENT "Running all unit tests..."
    COMMAND ${CMAKE_COMMAND} -E echo "Running all unit tests in src"
    COMMAND $<TARGET_FILE:array_unit_test>
    COMMAND $<TARGET_FILE:string_unit_test>
    COMMAND $<TARGET_FILE:twopointers_unit_test>
    COMMAND $<TARGET_FILE:slidingwindow_unit_test>
    COMMAND $<TARGET_FILE:matrix_unit_test>
    COMMAND $<TARGET_FILE:hashmap_unit_test>
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS ${ALL_TESTS}
)
