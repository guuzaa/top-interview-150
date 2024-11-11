#include "graph/graph.h"

#include <gtest/gtest.h>
#include <algorithm>

TEST(graphTest, numIslands) {
  struct TestCase {
    std::vector<std::vector<char>> grid;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {{
           {'1', '1', '1', '1', '0'},
           {'1', '1', '0', '1', '0'},
           {'1', '1', '0', '0', '0'},
           {'0', '0', '0', '0', '0'},
       },
       1},
      {{
           {'1', '1', '0', '0', '0'},
           {'1', '1', '0', '0', '0'},
           {'0', '0', '1', '0', '0'},
           {'0', '0', '0', '1', '1'},
       },
       3},
  };
  for (auto &&test : test_cases) {
    EXPECT_EQ(graph::numIslands(test.grid), test.expected);
  }
}

TEST(graphTest, solve) {
  struct TestCase {
    std::vector<std::vector<char>> board;
    std::vector<std::vector<char>> expected;
  };
  std::vector<TestCase> test_cases = {
      {{{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}},
       {{'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'O', 'X', 'X'}}},
  };
  for (auto &&test : test_cases) {
    graph::solve(test.board);
    EXPECT_EQ(test.board, test.expected);
  }
}

TEST(graphTest, calcEquation) {
  struct TestCase {
    std::vector<std::vector<std::string>> equations;
    std::vector<double> values;
    std::vector<std::vector<std::string>> queries;
    std::vector<double> expected;
  };
  std::vector<TestCase> test_cases = {
      {{{"a", "b"}, {"b", "c"}},
       {2.0, 3.0},
       {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}},
       {6.0, 0.5, -1.0, 1.0, -1.0}},
      {{{"a", "b"}}, {0.5}, {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}}, {0.5, 2.0, -1.0, -1.0}},
      {{{"a", "b"}, {"c", "d"}}, {1.0, 1.0}, {{"a", "c"}, {"b", "d"}, {"b", "a"}, {"d", "c"}}, {-1.0, -1.0, 1.0, 1.0}},
      {{{"a", "b"},
        {"a", "c"},
        {"a", "d"},
        {"a", "e"},
        {"a", "f"},
        {"a", "g"},
        {"a", "h"},
        {"a", "i"},
        {"a", "j"},
        {"a", "k"},
        {"a", "l"},
        {"a", "aa"},
        {"a", "aaa"},
        {"a", "aaaa"},
        {"a", "aaaaa"},
        {"a", "bb"},
        {"a", "bbb"},
        {"a", "ff"}},
       {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 1.0, 1.0, 1.0, 1.0, 1.0, 3.0, 5.0},
       {{"d", "f"},
        {"e", "g"},
        {"e", "k"},
        {"h", "a"},
        {"aaa", "k"},
        {"aaa", "i"},
        {"aa", "e"},
        {"aaa", "aa"},
        {"aaa", "ff"},
        {"bbb", "bb"},
        {"bb", "h"},
        {"bb", "i"},
        {"bb", "k"},
        {"aaa", "k"},
        {"k", "l"},
        {"x", "k"},
        {"l", "ll"}},
       {1.66667, 1.50000, 2.50000, 0.14286, 10.00000, 8.00000, 4.00000, 1.00000, 5.00000, 0.33333, 7.00000, 8.00000,
        10.00000, 10.00000, 1.10000, -1.00000, -1.00000}},
  };
  for (auto &&test : test_cases) {
    auto result = graph::calcEquation(test.equations, test.values, test.queries);
    std::for_each(result.begin(), result.end(),
                  [&test, i = 0](const auto &value) mutable { EXPECT_NEAR(value, test.expected[i++], 1e-5); });
  }
}

TEST(graphTest, canFinish) {
  struct TestCase {
    int numCourses;
    std::vector<std::vector<int>> prerequisites;
    bool expected;
  };
  std::vector<TestCase> test_cases = {
      {2, {{1, 0}}, true},
      {2, {{1, 0}, {0, 1}}, false},
  };
  for (auto &&test : test_cases) {
    EXPECT_EQ(graph::canFinish(test.numCourses, test.prerequisites), test.expected);
  }
}

TEST(graphTest, findOrder) {
  struct TestCase {
    int numCourses;
    std::vector<std::vector<int>> prerequisites;
    std::vector<int> expected;
  };
  std::vector<TestCase> test_cases = {
      {2, {{1, 0}}, {0, 1}},
      {4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}, {0, 1, 2, 3}},
  };
  for (auto &&test : test_cases) {
    EXPECT_EQ(graph::findOrder(test.numCourses, test.prerequisites), test.expected);
  }
}

TEST(graphTest, snakesAndLadders) {
  struct TestCase {
    std::vector<std::vector<int>> board;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {{{-1, -1}, {-1, 3}}, 1},
      {{{-1, 4}, {-1, 3}}, 1},
      {{{-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}},
       4},
  };
  for (auto &test : test_cases) {
    EXPECT_EQ(graph::snakesAndLadders(test.board), test.expected);
  }
}

TEST(graphTest, minMutation) {
  struct TestCase {
    std::string startGene;
    std::string endGene;
    std::vector<std::string> bank;
    int expected;
  };
  std::vector<TestCase> test_cases = {{"AACCGGTT", "AACCGGTA", {"AACCGGTA"}, 1},
                                      {"AACCGGTT", "AAACGGTA", {"AACCGGTA", "AACCGCTA", "AAACGGTA"}, 2},
                                      {"AACCGGTT", "AAACGGTA", {"AACCGATT", "AACCGATA", "AAACGATA", "AAACGGTA"}, 4}};
  for (auto &test : test_cases) {
    EXPECT_EQ(graph::minMutation(test.startGene, test.endGene, test.bank), test.expected);
  }
}

TEST(graphTest, ladderLength) {
  struct TestCase {
    std::string beginWord;
    std::string endWord;
    std::vector<std::string> wordList;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {"hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}, 5},
      {"hit", "cog", {"hot", "dot", "dog", "lot", "log"}, 0},
  };
  for (auto &test : test_cases) {
    EXPECT_EQ(graph::ladderLength(test.beginWord, test.endWord, test.wordList), test.expected);
  }
}