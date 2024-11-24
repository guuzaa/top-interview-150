#include "dp/dp.h"

#include <gtest/gtest.h>

TEST(dpTest, climbStairs) {
  struct TestCase {
    int n;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {2, 2}, {3, 3}, {4, 5}, {5, 8}, {45, 1836311903},
  };
  for (auto test_case : test_cases) {
    EXPECT_EQ(dp::climbStairs(test_case.n), test_case.expected);
  }
}

TEST(dpTest, rob) {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {{1, 2, 3, 1}, 4},
      {{2, 7, 9, 3, 1}, 12},
      {{2, 1, 1, 2}, 4},
      {{5, 5, 10, 100, 10, 5}, 110},
      {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 30},
      {{10, 1, 1, 10, 1, 1, 10}, 30},
      {{1, 3, 1, 3, 100}, 103},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(dp::rob(test_case.nums), test_case.expected);
  }
}

TEST(dpTest, wordBreak) {
  struct TestCase {
    std::string s;
    std::vector<std::string> wordDict;
    bool expected;
  };
  std::vector<TestCase> test_cases = {
      {"leetcode", {"leet", "code"}, true},
      {"applepenapple", {"apple", "pen"}, true},
      {"catsandog", {"cats", "dog", "sand", "and", "cat"}, false},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(dp::wordBreak(test_case.s, test_case.wordDict), test_case.expected);
  }
}

TEST(dpTest, coinChange) {
  struct TestCase {
    std::vector<int> coins;
    int amount;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {{1, 2, 5}, 11, 3},
      {{2}, 3, -1},
      {{1}, 0, 0},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(dp::coinChange(test_case.coins, test_case.amount), test_case.expected);
  }
}

TEST(dpTest, lengthOfLIS) {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {{10, 9, 2, 5, 3, 7, 101, 18}, 4},
      {{0, 1, 0, 3, 2, 3}, 4},
      {{7, 7, 7, 7, 7, 7, 7}, 1},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(dp::lengthOfLIS(test_case.nums), test_case.expected);
  }
}
