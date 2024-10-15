#include <benchmark/benchmark.h>
#include <vector>

#include "lib/lib.h"

static void BM_VectorPushBack(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> v;
    for (int i = 0; i < state.range(0); ++i) {
      v.push_back(i);
    }
  }
}

// Register the function as a benchmark
BENCHMARK(BM_VectorPushBack)->Arg(1000)->Arg(10000)->Arg(100000);

BENCHMARK_MAIN();