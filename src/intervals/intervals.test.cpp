#include "intervals/intervals.h"

#include <gtest/gtest.h>

TEST(intervalsTest, summaryRanges) {
  struct TestCase {
    std::vector<int> nums;
    std::vector<std::string> want;
  };

  std::vector<TestCase> tests = {
      {{}, {}}, {{0, 1, 2, 4, 5, 7}, {"0->2", "4->5", "7"}}, {{0, 2, 3, 4, 6, 8, 9}, {"0", "2->4", "6", "8->9"}}};

  for (auto &&test : tests) {
    EXPECT_EQ(intervals::summaryRanges(test.nums), test.want);
  }
}

TEST(intervalsTest, merge) {
  struct TestCase {
    std::vector<std::vector<int>> intervals;
    std::vector<std::vector<int>> want;
  };
  std::vector<TestCase> tests = {{{{1, 3}, {2, 6}, {8, 10}, {15, 18}}, {{1, 6}, {8, 10}, {15, 18}}},
                                 {
                                     {{1, 4}, {4, 5}},
                                     {{1, 5}},
                                 }};
  for (auto &&test : tests) {
    EXPECT_EQ(intervals::merge(test.intervals), test.want);
  }
}

TEST(intervalsTest, insert) {
  struct TestCase {
    std::vector<std::vector<int>> intervals;
    std::vector<int> newInterval;
    std::vector<std::vector<int>> want;
  };
  std::vector<TestCase> tests = {
      {{{1, 5}}, {2, 3}, {{1, 5}}},
      {{{1, 5}}, {2, 7}, {{1, 7}}},
      {{{1, 5}}, {6, 8}, {{1, 5}, {6, 8}}},
      {{{1, 5}}, {0, 3}, {{0, 5}}},
      {{{1, 5}}, {0, 0}, {{0, 0}, {1, 5}}},
      {{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, {4, 8}, {{1, 2}, {3, 10}, {12, 16}}},
  };
  for (auto &&test : tests) {
    EXPECT_EQ(intervals::insert(test.intervals, test.newInterval), test.want);
  }
}

TEST(intervalsTest, findMinArrowShots) {
  struct TestCase {
    std::vector<std::vector<int>> points;
    int want;
  };
  std::vector<TestCase> tests = {{{{1, 2}, {3, 4}, {5, 6}, {7, 8}}, 4},
                                 {{{10, 16}, {2, 8}, {1, 6}, {7, 12}}, 2},
                                 {{{1, 2}, {2, 3}, {3, 4}, {4, 5}}, 2},
                                 {{{-2147483646, -2147483645}, {2147483646, 2147483647}}, 2}};
  for (auto &&test : tests) {
    EXPECT_EQ(intervals::findMinArrowShots(test.points), test.want);
  }
}