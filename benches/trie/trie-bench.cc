#include <benchmark/benchmark.h>

#include "trie/trie.h"

using namespace std::string_literals;
using namespace std::string_view_literals;

static void BM_TrieString(benchmark::State &state) {
  for (auto _ : state) {
    trie::WordDictionary wordDictionary;
    for (int i = 0; i < state.range(0); ++i) {
      wordDictionary.addWord("aaaabbbbccccdddddeeeee"s);
      wordDictionary.search("aaaabbbbccccdddddeeeee"s);
      wordDictionary.search("aaaa.bbbccccdddddeeeee"s);
      wordDictionary.search("aaaa..bbccccdddddeeeee"s);
      wordDictionary.search("aaaa.bbbccccd.dddeeeee"s);
    }
  }
}

static void BM_TrieStringView(benchmark::State &state) {
  for (auto _ : state) {
    trie::WordDictionary wordDictionary;
    for (int i = 0; i < state.range(0); ++i) {
      wordDictionary.addWord("aaaabbbbccccdddddeeeee"sv);
      wordDictionary.search("aaaabbbbccccdddddeeeee"sv);
      wordDictionary.search("aaaa.bbbccccdddddeeeee"sv);
      wordDictionary.search("aaaa..bbccccdddddeeeee"sv);
      wordDictionary.search("aaaa.bbbccccd.dddeeeee"sv);
    }
  }
}

// Register the function as a benchmark
BENCHMARK(BM_TrieString)->Arg(1000)->Arg(10000)->Arg(100000);
BENCHMARK(BM_TrieStringView)->Arg(1000)->Arg(10000)->Arg(100000);

BENCHMARK_MAIN();