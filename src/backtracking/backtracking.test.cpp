#include "backtracking/backtracking.h"
#include <gtest/gtest.h>

TEST(backtrackingTest, letterCombinations) {
  struct TestCase {
    std::string digits;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases = {
      {"23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}},
      {"", {}},
      {"2", {"a", "b", "c"}},
      {"9", {"w", "x", "y", "z"}},
  };

  for (const auto &test_case : test_cases) {
    EXPECT_EQ(backtracking::letterCombinations(test_case.digits), test_case.expected);
  }
}

TEST(backtrackingTest, combine) {
  struct TestCase {
    int n;
    int k;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases = {
      {4, 2, {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}}},
      {1, 1, {{1}}},
  };

  for (const auto &test_case : test_cases) {
    EXPECT_EQ(backtracking::combine(test_case.n, test_case.k), test_case.expected);
  }
}

TEST(backtrackingTest, permute) {
  struct TestCase {
    std::vector<int> nums;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases = {
      {{1, 2, 3}, {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}}},
      {{0, 1}, {{0, 1}, {1, 0}}},
      {{1}, {{1}}},
  };

  for (auto &test_case : test_cases) {
    auto result = backtracking::permute(test_case.nums);
    std::sort(result.begin(), result.end());
    EXPECT_EQ(result, test_case.expected);
  }
}

TEST(backtrackingTest, combinationSum) {
  struct TestCase {
    std::vector<int> candidates;
    int target;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases = {
      {{2, 3, 6, 7}, 7, {{2, 2, 3}, {7}}},
      {{2, 3, 5}, 8, {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}}},
      {{2}, 1, {}},
  };

  for (auto &test_case : test_cases) {
    EXPECT_EQ(backtracking::combinationSum(test_case.candidates, test_case.target), test_case.expected);
  }
}

TEST(backtrackingTest, totalNQueens) {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases = {
      {1, 1}, {2, 0}, {3, 0}, {4, 2}, {5, 10}, {6, 4}, {7, 40}, {8, 92}, {9, 352},
  };

  for (const auto &test_case : test_cases) {
    EXPECT_EQ(backtracking::totalNQueens(test_case.n), test_case.expected);
  }
}

TEST(backtrackingTest, generateParenthesis) {
  struct TestCase {
    int n;
    std::vector<std::string> expected;
  };

  std::vector<TestCase> test_cases = {
      {3, {"((()))", "(()())", "(())()", "()(())", "()()()"}},
      {1, {"()"}},
      {2, {"(())", "()()"}},
      {4,
       {"(((())))", "((()()))", "((())())", "((()))()", "(()(()))", "(()()())", "(()())()", "(())(())", "(())()()",
        "()((()))", "()(()())", "()(())()", "()()(())", "()()()()"}},
  };

  for (auto &test_case : test_cases) {
    auto result = backtracking::generateParenthesis(test_case.n);
    EXPECT_EQ(result, test_case.expected);
  }
}

TEST(backtrackingTest, exist) {
  struct TestCase {
    std::vector<std::vector<char>> board;
    std::string word;
    bool expected;
  };

  std::vector<TestCase> test_cases = {
      {{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "ABCCED", true},
      {{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "SEE", true},
      {{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "ABCB", false},
  };

  for (auto &test_case : test_cases) {
    EXPECT_EQ(backtracking::exist(test_case.board, test_case.word), test_case.expected);
  }
}
