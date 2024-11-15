#include "binarysearch/binarysearch.h"

#include <gtest/gtest.h>

TEST(binarysearchTest, searchInsert) {
  struct TestCase {
    std::vector<int> nums;
    int target;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {{1, 3, 5, 6}, 5, 2},
      {{1, 3, 5, 6}, 4, 2},
      {{1, 3, 5, 6}, 2, 1},
      {{1, 3, 5, 6}, 7, 4},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(binarysearch::searchInsert(test_case.nums, test_case.target), test_case.expected);
  }
}

TEST(binarysearchTest, searchMatrix) {
  struct TestCase {
    std::vector<std::vector<int>> matrix;
    int target;
    bool expected;
  };
  std::vector<TestCase> test_cases = {
      {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 3, true},
      {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 13, false},
      {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 16, true},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(binarysearch::searchMatrix(test_case.matrix, test_case.target), test_case.expected);
  }
}

TEST(binarysearchTest, findPeakElement) {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {{1, 2, 3, 1}, 2},
      {{1, 2, 1, 3, 5, 6, 4}, 5},
      {{1, 2, 4, 3, 5, 6, 4}, 5},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(binarysearch::findPeakElement(test_case.nums), test_case.expected);
  }
}

TEST(binarysearchTest, search) {
  struct TestCase {
    std::vector<int> nums;
    int target;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {{4, 5, 6, 7, 0, 1, 2}, 0, 4},
      {{4, 5, 6, 7, 0, 1, 2}, 3, -1},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(binarysearch::search(test_case.nums, test_case.target), test_case.expected);
  }
}

TEST(binarysearchTest, searchRange) {
  struct TestCase {
    std::vector<int> nums;
    int target;
    std::vector<int> expected;
  };
  std::vector<TestCase> test_cases = {
      {{5, 7, 7, 8, 8, 10}, 8, {3, 4}},
      {{5, 7, 7, 8, 10}, 8, {3, 3}},
      {{5, 7, 7, 8, 8, 10}, 6, {-1, -1}},
      {{}, 0, {-1, -1}},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(binarysearch::searchRange(test_case.nums, test_case.target), test_case.expected);
  }
}

TEST(binarysearchTest, findMin) {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {{3, 4, 5, 1, 2}, 1},
      {{4, 5, 6, 7, 0, 1, 2}, 0},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(binarysearch::findMin(test_case.nums), test_case.expected);
  }
}

TEST(binarysearchTest, findMedianSortedArrays) {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    double expected;
  };
  std::vector<TestCase> test_cases = {
      {{1, 3}, {2}, 2.0},
      {{}, {2}, 2.0},
      {{1, 2}, {3, 4}, 2.5},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(binarysearch::findMedianSortedArrays(test_case.nums1, test_case.nums2), test_case.expected);
  }
}