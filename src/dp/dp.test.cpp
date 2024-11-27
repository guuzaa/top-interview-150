#include "dp/dp.h"

#include <gtest/gtest.h>
#include <unordered_set>

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

TEST(dpTest, minimumTotal) {
  struct TestCase {
    std::vector<std::vector<int>> triangle;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}, 11},
      {{{{-10}}}, -10},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(dp::minimumTotal(test_case.triangle), test_case.expected);
  }
}

TEST(dpTest, minPathSum) {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 7},
      {{{1, 2, 3}, {4, 5, 6}}, 12},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(dp::minPathSum(test_case.grid), test_case.expected);
  }
}

TEST(dpTest, uniquePathsWithObstacles) {
  struct TestCase {
    std::vector<std::vector<int>> obstacleGrid;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, 2},
      {{{0, 1}, {0, 0}}, 1},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(dp::uniquePathsWithObstacles(test_case.obstacleGrid), test_case.expected);
  }
}

TEST(dpTest, longestPalindrome) {
  struct TestCase {
    std::string s;
    std::unordered_set<std::string> expected;
  };
  std::vector<TestCase> test_cases = {
      {"babad", {"bab", "aba"}},
      {"cbbd", {"bb"}},
      {"b", {"b"}},
      {"bb", {"bb"}},
  };
  for (auto &test_case : test_cases) {
    EXPECT_TRUE(test_case.expected.count(dp::longestPalindrome(test_case.s)));
  }
}

TEST(dpTest, isInterleave) {
  struct TestCase {
    std::string s1;
    std::string s2;
    std::string s3;
    bool expected;
  };
  std::vector<TestCase> test_cases = {
      {"aabcc", "dbbca", "aadbbcbcac", true},
      {"aabcc", "dbbca", "aadbbbaccc", false},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(dp::isInterleave(test_case.s1, test_case.s2, test_case.s3), test_case.expected);
  }
}

TEST(dpTest, minDistance) {
  struct TestCase {
    std::string word1;
    std::string word2;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {"horse", "ros", 3},
      {"intention", "execution", 5},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(dp::minDistance(test_case.word1, test_case.word2), test_case.expected);
  }
}

TEST(dpTest, maxProfit3) {
  struct TestCase {
    std::vector<int> prices;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {{3, 3, 5, 0, 0, 3, 1, 4}, 6},
      {{1, 2, 3, 4, 5}, 4},
      {{7, 6, 4, 3, 1}, 0},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(dp::maxProfit3(test_case.prices), test_case.expected);
  }
}

TEST(dpTest, maxProfit4) {
  struct TestCase {
    int k;
    std::vector<int> prices;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {2, {2, 4, 1}, 2},
      {2, {3, 2, 6, 5, 0, 3}, 7},
      {2, {6, 1, 3, 2, 4, 7}, 7},
  };

  for (auto &test_case : test_cases) {
    EXPECT_EQ(dp::maxProfit4(test_case.k, test_case.prices), test_case.expected);
  }
}

TEST(dpTest, maximalSquare) {
  struct TestCase {
    std::vector<std::vector<char>> matrix;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {{{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}}, 4},
      {{{'0', '1'}, {'1', '0'}}, 1},
      {{{'0'}}, 0},
      {{{'1'}}, 1},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(dp::maximalSquare(test_case.matrix), test_case.expected);
  }
}
