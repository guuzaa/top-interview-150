set(googletest_version 1.15.0)
set(benchmark_version 1.8.5)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL "https://github.com/google/googletest/archive/refs/tags/v${googletest_version}.zip"
)

FetchContent_Declare(
    benchmark
    URL "https://github.com/google/benchmark/archive/refs/tags/v${benchmark_version}.zip"
)

function(include_googletest)
    FetchContent_MakeAvailable(googletest)
endfunction(include_googletest)

function(include_benchmark)
    FetchContent_MakeAvailable(benchmark)
endfunction(include_benchmark)
