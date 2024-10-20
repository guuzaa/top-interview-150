#include "array/array.h"
#include <gtest/gtest.h>
#include <limits>
#include <unordered_set>

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

TEST(ArrayTest, MaxProfit2Test) {
  struct Case {
    std::vector<int> prices;
    int expected_profit;
  };
  std::vector<Case> cases = {
      {{7, 1, 5, 3, 6, 4}, 7},
      {{1, 2, 3, 4, 5}, 4},
      {{7, 6, 4, 3, 1}, 0},
      {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 9},
      {{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 0},
      {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, 19},
      {{2, 4, 1}, 2},
      {{3, 2, 6, 5, 0, 3}, 7},
      {{1, 2, 4, 2, 5, 7, 2, 4, 9}, 15},
  };

  for (auto &c : cases) {
    int result = maxProfit2(c.prices);
    EXPECT_EQ(result, c.expected_profit);
  }
}

TEST(ArrayTest, CanJumpTest) {
  struct Case {
    std::vector<int> nums;
    bool expected_can_jump;
  };
  std::vector<Case> cases = {
      {{2, 3, 1, 1, 4}, true},
      {{3, 2, 1, 0, 4}, false},
      {{1, 2, 3}, true},
      {{0}, true},
      {{1}, true},
      {{0, 2, 3}, false},
      {{2, 0, 0, 1, 4}, false},
      {{3, 0, 8, 2, 0, 0, 1}, true},
      {{5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0}, true},
      {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, true},
      {{3, 2, 1, 0, 4, 5, 6, 7, 8, 9, 10}, false},
      {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false},
      {{5, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, false},
      {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, true},
  };

  for (auto &c : cases) {
    bool result = canJump(c.nums);
    EXPECT_EQ(result, c.expected_can_jump);
  }
}

TEST(ArrayTest, JumpTest) {
  struct Case {
    std::vector<int> nums;
    int expected_jumps;
  };
  std::vector<Case> cases = {{{2, 3, 1, 1, 4}, 2},
                             {{1, 2, 3}, 2},
                             {{1, 2, 1, 1, 1}, 3},
                             {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 19},
                             {{1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 18}};
  for (auto &c : cases) {
    int result = jump(c.nums);
    EXPECT_EQ(result, c.expected_jumps);
  }
}

TEST(ArrayTest, HIndexTest) {
  struct Case {
    std::vector<int> citations;
    int expected_h_index;
  };
  std::vector<Case> cases = {{{3, 0, 6, 1, 5}, 3},  {{1, 3, 1}, 1}, {{0, 1, 3, 5, 6}, 3}, {{1, 2, 100}, 2},
                             {{11, 15}, 2},         {{1}, 1},       {{1, 1, 1, 1, 1}, 1}, {{10, 8, 5, 4, 3}, 4},
                             {{25, 8, 5, 3, 3}, 3}, {{100}, 1}};

  for (auto &c : cases) {
    int result = hIndex(c.citations);
    EXPECT_EQ(result, c.expected_h_index);
  }
}

TEST(ArrayTest, RandomizedSetTest) {
  RandomizedSet rs;

  // Test multiple inserts and removes
  EXPECT_TRUE(rs.insert(10));
  EXPECT_TRUE(rs.insert(20));
  EXPECT_TRUE(rs.insert(30));
  EXPECT_FALSE(rs.insert(20));  // Duplicate insert should fail
  EXPECT_TRUE(rs.remove(20));
  EXPECT_FALSE(rs.remove(20));  // Removing non-existent element should fail

  // Test getRandom
  std::unordered_set<int> expected_values = {10, 30};
  for (int i = 0; i < 100; ++i) {
    int random_val = rs.getRandom();
    EXPECT_TRUE(expected_values.count(random_val));
  }

  // Test large number of operations
  for (int i = 100; i < 1000; ++i) {
    EXPECT_TRUE(rs.insert(i));
  }
  for (int i = 100; i < 1000; ++i) {
    EXPECT_TRUE(rs.remove(i));
  }

  // Test edge cases
  EXPECT_TRUE(rs.insert(std::numeric_limits<int>::max()));
  EXPECT_TRUE(rs.insert(std::numeric_limits<int>::min()));
  EXPECT_TRUE(rs.remove(std::numeric_limits<int>::max()));
  EXPECT_TRUE(rs.remove(std::numeric_limits<int>::min()));
}

TEST(ArrayTest, ProductExceptSelfTest) {
  struct Case {
    std::vector<int> nums;
    std::vector<int> expected;
  };
  std::vector<Case> cases = {{{1, 2, 3, 4}, {24, 12, 8, 6}},
                             {{0, 0}, {0, 0}},
                             {{-1, 1, 0, -3, 3}, {0, 0, 9, 0, 0}},
                             {{1, 1, 1, 1}, {1, 1, 1, 1}},
                             {{2, 3, 4, 5}, {60, 40, 30, 24}},
                             {{-2, -3, 4, -5}, {60, 40, -30, 24}},
                             {{1, 2, 3, 0, 5}, {0, 0, 0, 30, 0}},
                             {{1}, {1}},
                             {{1, 2}, {2, 1}},
                             {{10, 10, 10, 10, 10}, {10000, 10000, 10000, 10000, 10000}}};

  for (auto &c : cases) {
    std::vector<int> result = productExceptSelf(c.nums);
    EXPECT_EQ(result, c.expected);
  }
}

TEST(ArrayTest, CanCompleteCircuitTest) {
  struct Case {
    std::vector<int> gas;
    std::vector<int> cost;
    int expected_index;
  };
  std::vector<Case> cases = {{{1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}, 3},
                             {{2, 3, 4}, {3, 4, 3}, -1},
                             {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, 0},
                             {{5, 1, 2, 3, 4}, {4, 4, 1, 5, 1}, 4},
                             {{4}, {5}, -1},
                             {{5}, {4}, 0},
                             {{3, 3, 4}, {3, 4, 4}, -1},
                             {{1, 2, 3, 4, 5, 5, 70}, {2, 3, 4, 3, 9, 6, 2}, 6},
                             {{2, 3, 4}, {3, 4, 3}, -1},
                             {{0}, {0}, 0}};

  for (auto &c : cases) {
    int result = canCompleteCircuit(c.gas, c.cost);
    EXPECT_EQ(result, c.expected_index);
  }
}

TEST(ArrayTest, CandyTest) {
  struct Case {
    std::vector<int> ratings;
    int expected_min_candies;
  };
  std::vector<Case> cases = {{{1, 0, 2}, 5}, {{1, 2, 2}, 4}, {{1, 3, 2, 2, 1}, 7}, {{1, 2, 3, 4, 5, 3, 2}, 18}};
  for (auto &c : cases) {
    int result = candy(c.ratings);
    EXPECT_EQ(result, c.expected_min_candies);
  }
}

TEST(ArrayTest, TrapTest) {
  struct Case {
    std::vector<int> height;
    int expected_water;
  };
  std::vector<Case> cases = {{{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6},
                             {{4, 2, 0, 3, 2, 5}, 9},
                             {{0, 0, 0, 0}, 0},
                             {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 0},
                             {{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 0}};
  for (auto &c : cases) {
    int result = trap(c.height);
    EXPECT_EQ(result, c.expected_water);
  }
}
