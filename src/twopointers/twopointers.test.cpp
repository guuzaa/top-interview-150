#include "twopointers/twopointers.h"

#include <gtest/gtest.h>

TEST(twopointers, isPalindrome) {
  struct Case {
    std::string s;
    bool expected;
  };
  std::vector<Case> cases = {
      {"A man, a plan, a canal: Panama", true},
      {"race a car", false},
      {" ", true},
  };
  for (const auto &c : cases) {
    EXPECT_EQ(twopointers::isPalindrome(c.s), c.expected);
  }
}

TEST(twopointers, isSubsequence) {
  struct Case {
    std::string s;
    std::string t;
    bool expected;
  };
  std::vector<Case> cases = {{"abc", "ahbgdc", true}, {"axc", "ahbgdc", false}, {"", "ahbgdc", true},
                             {"", "", true},          {"abc", "", false},       {"a", "a", true},
                             {"ace", "abcde", true},  {"aec", "abcde", false},  {"aaaaaa", "bbaaaa", false},
                             {"ab", "baab", true}};
  for (const auto &c : cases) {
    EXPECT_EQ(twopointers::isSubsequence(c.s, c.t), c.expected);
  }
}

TEST(twopointers, twoSum) {
  struct Case {
    std::vector<int> nums;
    int target;
    std::vector<int> expected;
  };
  std::vector<Case> cases = {{{2, 7, 11, 15}, 9, {1, 2}}, {{2, 3, 4}, 6, {1, 3}},
                             {{-1, 0}, -1, {1, 2}},       {{1, 2, 3, 4, 5}, 9, {4, 5}},
                             {{1, 2, 3, 4}, 7, {3, 4}},   {{-2, -1, 0, 1}, 0, {2, 4}},
                             {{1, 1}, 2, {1, 2}},         {{-1000, 1000}, 0, {1, 2}},
                             {{5, 25, 75}, 100, {2, 3}},  {{3, 24, 50, 79, 88, 150, 345}, 200, {3, 6}}};
  for (auto &&c : cases) {
    EXPECT_EQ(twopointers::twoSum(c.nums, c.target), c.expected);
  }
}

TEST(twopointers, maxArea) {
  struct Case {
    std::vector<int> height;
    int expected;
  };
  std::vector<Case> cases = {
      {{1, 8, 6, 2, 5, 4, 8, 3, 7}, 49},
      {{1, 1}, 1},
      {{4, 3, 2, 1, 4}, 16},
      {{1, 2, 1}, 2},
  };
  for (auto &&c : cases) {
    EXPECT_EQ(twopointers::maxArea(c.height), c.expected);
  }
}

TEST(twopointers, threeSum) {
  struct Case {
    std::vector<int> nums;
    std::vector<std::vector<int>> expected;
  };
  std::vector<Case> cases = {
      {{0, 0, 0}, {{0, 0, 0}}},
      {{-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}}},
      {{1, -1, -1, 0}, {{-1, 0, 1}}},
      {{-2, 0, 1, 1, 2}, {{-2, 0, 2}, {-2, 1, 1}}},
      {{-2, 0, 0, 2, 2}, {{-2, 0, 2}}},
      {{-4, -2, -1, 0, 1, 2, 3}, {{-4, 1, 3}, {-2, -1, 3}, {-2, 0, 2}, {-1, 0, 1}}},
      {{-1, -1, -1, 1, 1, 2}, {{-1, -1, 2}}},
      {{0, 0, 0, 0}, {{0, 0, 0}}},
      {{3, 0, -2, -1, 1, 2}, {{-2, -1, 3}, {-2, 0, 2}, {-1, 0, 1}}},
  };
  for (auto &&c : cases) {
    EXPECT_EQ(twopointers::threeSum(c.nums), c.expected);
  }
}
