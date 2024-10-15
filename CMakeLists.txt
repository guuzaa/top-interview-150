cmake_minimum_required(VERSION 3.10)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

include(Config)

project(${PROJ_NAME} VERSION ${VER} LANGUAGES C CXX)

string(COMPARE EQUAL ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR} PROJECT_IS_IN_ROOT)
set(CMAKE_EXPORT_COMPILE_COMMANDS ${PROJECT_IS_IN_ROOT})

if(PROJECT_IS_IN_ROOT)
    set(CMAKE_CXX_STANDARD ${CPP_STD})
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    message(STATUS "Project ${PROJECT_NAME}:${VER} is in root.")
endif(PROJECT_IS_IN_ROOT)

option(HAS_TESTS "Build and perform tests" ${PROJECT_IS_IN_ROOT})
option(HAS_BENCHES "Build and perform benches" ${PROJECT_IS_IN_ROOT})
option(HAS_EXAMPLES "Build and perform examples" ${PROJECT_IS_IN_ROOT})
option(HAS_CLANG_TOOLS "Build and use Clang tools" ${PROJECT_IS_IN_ROOT})
option(HAS_MSAN "Build and use Memory Sanitizer" ${PROJECT_IS_IN_ROOT})

# Includes
set(SRC_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/src/include)
include_directories(${SRC_INCLUDE_DIR})

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

if(HAS_BENCHES) 
    include(3rdParty)
    include_googletest()
    set(CMAKE_BUILD_TYPE Release)
    include_benchmark()
    message(STATUS "Building benches")
    add_subdirectory(benches)
endif(HAS_BENCHES) 

# The below needs to be built in Debug mode
set(CMAKE_BUILD_TYPE Debug)

if(HAS_MSAN)
    include(Sanitizers)
    message(STATUS "Building Sanitizers")
    define_sanitizer()
endif(HAS_MSAN)

if(HAS_TESTS) 
    include(3rdParty)
    include_googletest()
    message(STATUS "Building tests")
    add_subdirectory(tests)
endif(HAS_TESTS)

if(HAS_EXAMPLES) 
    message(STATUS "Building examples")
    add_subdirectory(examples)
endif(HAS_EXAMPLES) 

if(HAS_CLANG_TOOLS)
    include(ClangTools)
    define_clang_tidy_targets()
    define_clang_format_targets()
endif(HAS_CLANG_TOOLS)
