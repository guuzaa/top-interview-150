set(bench_dir_list "${CMAKE_CURRENT_SOURCE_DIR}/lib")

enable_testing()

foreach(bench_dir ${bench_dir_list})
    file(GLOB_RECURSE bench_files "${bench_dir}/*.cpp" "${bench_dir}/*.cc")
    get_filename_component(dir_name ${bench_dir} NAME_WE)

    set(bench_name ${dir_name}_bench)
    add_executable(${bench_name} EXCLUDE_FROM_ALL ${bench_files})
    target_link_libraries(${bench_name} PRIVATE lib_obj benchmark::benchmark)

    add_custom_target(
        bench-${dir_name}
        COMMENT "Running bench ${bench_name}..."
        COMMAND ${bench_name}
    )
    set_target_properties(${bench_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${BenchesBinaryPath}")

    list(APPEND BENCH_TARGETS ${bench_name})
    add_test(NAME ${bench_name} COMMAND ${bench_name})
endforeach(bench_dir ${bench_dir_list})

add_custom_target(run-benches
    COMMAND ${CMAKE_CTEST_COMMAND} -C Debug --verbose 
    DEPENDS ${BENCH_TARGETS}
    COMMENT "Building and runnig all benches..."
)
