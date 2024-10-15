function(define_sanitizer)
    if(NOT DEFINED SANITIZER)
        set(SANITIZER address)
    endif()

    message(STATUS "Build mode: ${CMAKE_BUILD_TYPE}")
    message(STATUS "${SANITIZER} sanitizer will be enabled in debug mode.")

    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -ggdb -fsanitize=${SANITIZER} -fno-omit-frame-pointer -fno-optimize-sibling-calls" PARENT_SCOPE)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb -fsanitize=${SANITIZER} -fno-omit-frame-pointer -fno-optimize-sibling-calls" PARENT_SCOPE)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endfunction(define_sanitizer)
