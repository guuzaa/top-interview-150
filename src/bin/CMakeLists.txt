get_source_files(bin_files "${CMAKE_CURRENT_SOURCE_DIR}")

foreach(bin_file ${bin_files})
    get_filename_component(bin_name ${bin_file} NAME_WE)
    add_executable(${bin_name} ${bin_file})
    target_link_libraries(${bin_name} PRIVATE ${ALL_OBJECTS})

    set_target_properties(${bin_name} 
        PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${BinBinaryPath}"
        COMMAND ${bin_name}
    )

    add_custom_target(
        "bin-${bin_name}"
        COMMENT "Running bin ${bin_file}..."
        COMMAND ${bin_name}
    )
endforeach(bin_file ${bin_files})
