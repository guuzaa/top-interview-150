get_current_directory_name(dir "${CMAKE_CURRENT_SOURCE_DIR}")
set(lib_name "${dir}_obj")

get_source_files(obj_files "${CMAKE_CURRENT_SOURCE_DIR}")
add_library(
    ${lib_name}
    OBJECT
    ${obj_files}
)

set(ALL_OBJECT_FILES ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:${lib_name}> PARENT_SCOPE)
set(ALL_OBJECTS ${ALL_OBJECTS} $<TARGET_NAME:${lib_name}> PARENT_SCOPE)

get_test_files(test_files "${CMAKE_CURRENT_SOURCE_DIR}")
if(test_files)
    include(3rdParty)
    include_googletest()
    set(test_name "${dir}_unit_test")
    add_executable(${test_name} EXCLUDE_FROM_ALL ${test_files})
    target_link_libraries(${test_name} PRIVATE ${lib_name} gtest gmock_main)

    set_target_properties(${test_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${UnitTestsBinaryPath}")

    add_custom_target(
        "unit-test-${dir}"
        COMMENT "Running unit-test ..."
        COMMAND ${test_name}
    )
endif(test_files)
