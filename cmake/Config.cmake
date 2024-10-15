# Descriptions for the project
set(PROJ_NAME cmaker)
set(VER 0.0.1)
set(CPP_STD 17)

set(unit_test_pattern ".test.")
set(supported_suffixes "cc" "cpp" "cxx" "c")

# Objects definition
set(ALL_OBJECTS "")
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-unused-parameter -Wno-attributes") 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter -Wno-attributes")

# Paths
set(UnitTestsBinaryPath "${CMAKE_BINARY_DIR}/unit-tests")
set(TestsBinaryPath "${CMAKE_BINARY_DIR}/tests")
set(BenchesBinaryPath "${CMAKE_BINARY_DIR}/benches")
set(ExamplesBinaryPath "${CMAKE_BINARY_DIR}/examples")
set(BinBinaryPath "${CMAKE_BINARY_DIR}/bin")

# Functions definition
function(append_to_list_elements list_out item pattern)
    foreach(suffix ${supported_suffixes})
        list(APPEND ret_list "${item}/*${pattern}${suffix}")
    endforeach(suffix ${supported_suffixes})
    set(${list_out} ${ret_list} PARENT_SCOPE)
endfunction(append_to_list_elements list_out item pattern)

function(get_current_directory_name dir_name cur_dir)
    get_filename_component(name ${cur_dir} NAME)
    set(${dir_name} ${name} PARENT_SCOPE)
endfunction(get_current_directory_name dir_name cur_dir)

function(get_source_files output_var curr_dir)
    append_to_list_elements(glob_patterns ${curr_dir} ".")
    file(GLOB all_files ${glob_patterns})

    set(filtered_files)

    foreach(file ${all_files})
        if(NOT file MATCHES ${unit_test_pattern})
            list(APPEND filtered_files ${file})
        endif(NOT file MATCHES ${unit_test_pattern})
    endforeach(file ${all_files})

    set(${output_var} ${filtered_files} PARENT_SCOPE)
endfunction(get_source_files output_var curr_dir)

function(get_test_files output_var curr_dir)
    append_to_list_elements(glob_patterns ${curr_dir} "${unit_test_pattern}")
    file(GLOB all_files ${glob_patterns})
    set(${output_var} ${all_files} PARENT_SCOPE)
endfunction(get_test_files output_var curr_dir)
