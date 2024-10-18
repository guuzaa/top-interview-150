#include "array/array.h"
#include <gtest/gtest.h>

using namespace array;

TEST(ArrayTest, MergeTest) {
  struct Case {
    std::vector<int> nums1;
    int m;
    std::vector<int> nums2;
    int n;
    std::vector<int> expected;
  };
  std::vector<Case> cases = {{{0}, 0, {}, 0, {0}},
                             {{0, 0, 0}, 0, {1, 2, 3}, 3, {1, 2, 3}},
                             {{1, 2, 3}, 3, {}, 0, {1, 2, 3}},
                             {{1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3, {1, 2, 2, 3, 5, 6}},
                             {{-1, 0, 0, 3, 3, 3, 0, 0, 0}, 6, {-1, -1, 0}, 3, {-1, -1, -1, 0, 0, 0, 3, 3, 3}},
                             {{1, 2, 2, 3, 0, 0, 0}, 4, {2, 5, 6}, 3, {1, 2, 2, 2, 3, 5, 6}},
                             {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              10,
                              {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
                              10,
                              {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}},
                             {{100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              10,
                              {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                              10,
                              {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000}},
                             {{-50, -40, -30, -20, -10, 0, 10, 20, 30, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              10,
                              {-45, -35, -25, -15, -5, 5, 15, 25, 35, 45},
                              10,
                              {-50, -45, -40, -35, -30, -25, -20, -15, -10, -5, 0, 5, 10, 15, 20, 25, 30, 35, 40, 45}}};

  for (auto &c : cases) {
    merge(c.nums1, c.m, c.nums2, c.n);
    EXPECT_EQ(c.nums1, c.expected);
  }
}

TEST(ArrayTest, RemoveElementTest) {
  struct Case {
    std::vector<int> nums;
    int val;
    int expected_count;
    std::vector<int> expected_nums;
  };
  std::vector<Case> cases = {{{3, 2, 2, 3}, 3, 2, {2, 2}},
                             {{0, 1, 2, 2, 3, 0, 4, 2}, 2, 5, {0, 1, 3, 0, 4}},
                             {{}, 1, 0, {}},
                             {{1, 1, 1}, 1, 0, {}},
                             {{1, 2, 3, 4, 5}, 6, 5, {1, 2, 3, 4, 5}},
                             {{1, 1, 2, 2, 3, 3, 4, 4}, 2, 6, {1, 1, 3, 3, 4, 4}},
                             {{5, 5, 5, 5, 5}, 5, 0, {}},
                             {{5, 5, 5, 5, 5}, 1, 5, {5, 5, 5, 5, 5}},
                             {{1, 2, 3, 4, 5, 1, 2, 3, 4, 5}, 3, 8, {1, 2, 4, 5, 1, 2, 4, 5}}};

  for (auto &c : cases) {
    int result = removeElement(c.nums, c.val);
    EXPECT_EQ(result, c.expected_count);
    c.nums.resize(c.expected_count);
    EXPECT_EQ(c.nums, c.expected_nums);
  }
}

TEST(ArrayTest, RemoveDuplicatesTest) {
  struct Case {
    std::vector<int> nums;
    int expected_count;
    std::vector<int> expected_nums;
  };
  std::vector<Case> cases = {{{1, 1, 2}, 2, {1, 2}},
                             {{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, 5, {0, 1, 2, 3, 4}},
                             {{1, 1, 1, 1, 1}, 1, {1}},
                             {{1, 2, 3, 4, 5}, 5, {1, 2, 3, 4, 5}},
                             {{1, 2, 2, 3, 3, 3, 4, 4, 4, 4}, 4, {1, 2, 3, 4}},
                             {{-3, -3, -2, -1, -1, 0, 0, 0, 1, 2, 2, 3}, 7, {-3, -2, -1, 0, 1, 2, 3}},
                             {{1, 1, 2, 2, 3, 3}, 3, {1, 2, 3}},
                             {{1}, 1, {1}}};

  for (auto &c : cases) {
    int result = removeDuplicates(c.nums);
    EXPECT_EQ(result, c.expected_count);
    c.nums.resize(c.expected_count);
    EXPECT_EQ(c.nums, c.expected_nums);
  }
}

TEST(ArrayTest, RemoveDuplicates2Test) {
  struct Case {
    std::vector<int> nums;
    int expected_count;
    std::vector<int> expected_nums;
  };
  std::vector<Case> cases = {{{1, 1, 1, 2, 2, 3}, 5, {1, 1, 2, 2, 3}},
                             {{0, 0, 1, 1, 1, 1, 2, 3, 3}, 7, {0, 0, 1, 1, 2, 3, 3}},
                             {{1, 1, 1, 2, 2, 2, 3, 3}, 6, {1, 1, 2, 2, 3, 3}},
                             {{1, 2, 3, 4, 5}, 5, {1, 2, 3, 4, 5}},
                             {{1, 1, 1, 1, 1, 1}, 2, {1, 1}},
                             {{1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4}, 7, {1, 2, 2, 3, 3, 4, 4}},
                             {{-1, -1, 0, 0, 0, 1, 1, 1, 2, 2, 3}, 9, {-1, -1, 0, 0, 1, 1, 2, 2, 3}},
                             {{1}, 1, {1}}};

  for (auto &c : cases) {
    int result = removeDuplicates2(c.nums);
    EXPECT_EQ(result, c.expected_count);
    c.nums.resize(c.expected_count);
    EXPECT_EQ(c.nums, c.expected_nums);
  }
}

TEST(ArrayTest, MajorityElementTest) {
  struct Case {
    std::vector<int> nums;
    int expected_majority;
  };
  std::vector<Case> cases = {
      {{3, 2, 3}, 3},          {{2, 2, 1, 1, 1, 2, 2}, 2}, {{1}, 1},
      {{5, 5, 5, 5, 5}, 5},    {{1, 1, 1, 2}, 1},          {{0, 1, 0, 1, 0, 1, 0}, 0},
      {{2, 2, 2, 2, 2, 2}, 2},
  };

  for (auto &c : cases) {
    int result = majorityElement(c.nums);
    EXPECT_EQ(result, c.expected_majority);
  }
}

TEST(ArrayTest, RotateTest) {
  struct Case {
    std::vector<int> nums;
    int k;
    std::vector<int> expected_nums;
  };
  std::vector<Case> cases = {
      {{1, 2, 3, 4, 5, 6, 7}, 3, {5, 6, 7, 1, 2, 3, 4}},
      {{1, 2, 3, 4, 5, 6, 7}, 10, {5, 6, 7, 1, 2, 3, 4}},
      {{1, 2, 3, 4, 5, 6, 7}, 0, {1, 2, 3, 4, 5, 6, 7}},
      {{1, 2, 3, 4, 5, 6, 7}, 1, {7, 1, 2, 3, 4, 5, 6}},
      {{1, 2, 3, 4, 5, 6, 7}, 2, {6, 7, 1, 2, 3, 4, 5}},
      {{1, 2, 3, 4, 5, 6, 7}, 3, {5, 6, 7, 1, 2, 3, 4}},
      {{1}, 2, {1}},
      {{1}, 1, {1}},
  };

  for (auto &c : cases) {
    rotate(c.nums, c.k);
    EXPECT_EQ(c.nums, c.expected_nums);
  }
}

TEST(ArrayTest, MaxProfitTest) {
  struct Case {
    std::vector<int> prices;
    int expected_profit;
  };
  std::vector<Case> cases = {
      {{7, 1, 5, 3, 6, 4}, 5},
      {{7, 6, 4, 3, 1}, 0},
      {{1, 2, 3, 4, 5}, 4},
      {{3, 3, 5, 0, 0, 3, 1, 4}, 4},
      {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 9},
      {{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 0},
      {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, 19},
      {{2, 4, 1}, 2},
      {{3, 2, 6, 5, 0, 3}, 4},
      {{1, 2, 4, 2, 5, 7, 2, 4, 9}, 8},
  };

  for (auto &c : cases) {
    int result = maxProfit(c.prices);
    EXPECT_EQ(result, c.expected_profit);
  }
}
