add_subdirectory(array)
add_subdirectory(string)
add_subdirectory(twopointers)
add_subdirectory(slidingwindow)
add_subdirectory(matrix)
add_subdirectory(hashmap)
add_subdirectory(intervals)
add_subdirectory(stack)
add_subdirectory(linkedlist)
add_subdirectory(binarytree)
add_subdirectory(graph)
add_subdirectory(trie)
add_subdirectory(binarysearch)
add_subdirectory(backtracking)
add_subdirectory(tree)
add_subdirectory(bit)
add_subdirectory(heap)
add_subdirectory(dp)
add_subdirectory(math)

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
    COMMAND $<TARGET_FILE:intervals_unit_test>
    COMMAND $<TARGET_FILE:stack_unit_test>
    COMMAND $<TARGET_FILE:linkedlist_unit_test>
    COMMAND $<TARGET_FILE:binarytree_unit_test>
    COMMAND $<TARGET_FILE:graph_unit_test>
    COMMAND $<TARGET_FILE:trie_unit_test>
    COMMAND $<TARGET_FILE:binarysearch_unit_test>
    COMMAND $<TARGET_FILE:backtracking_unit_test>
    COMMAND $<TARGET_FILE:tree_unit_test>
    COMMAND $<TARGET_FILE:bit_unit_test>
    COMMAND $<TARGET_FILE:heap_unit_test>
    COMMAND $<TARGET_FILE:dp_unit_test>
    COMMAND $<TARGET_FILE:math_unit_test>
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS ${ALL_TESTS}
)
