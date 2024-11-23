#include "heap/heap.h"
#include "gtest/gtest.h"

TEST(HeapTest, findKthLargest) {
  struct TestCase {
    std::vector<int> nums;
    int k;
    int expected;
  };

  std::vector<TestCase> testCases = {
      {.nums = {3, 2, 1, 5, 6, 4}, .k = 2, .expected = 5},
      {.nums = {3, 2, 3, 1, 2, 4, 5, 5, 6}, .k = 4, .expected = 4},
  };
  for (auto &testCase : testCases) {
    EXPECT_EQ(heap::findKthLargest(testCase.nums, testCase.k), testCase.expected);
  }
}

TEST(HeapTest, kSmallestPairs) {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    int k;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> testCases = {
      {.nums1 = {1, 7, 11}, .nums2 = {2, 4, 6}, .k = 3, .expected = {{1, 2}, {1, 4}, {1, 6}}},
      {.nums1 = {1, 1, 2}, .nums2 = {1, 2, 3}, .k = 2, .expected = {{1, 1}, {1, 1}}},
      {.nums1 = {1, 2}, .nums2 = {3}, .k = 3, .expected = {{1, 3}, {2, 3}}},
  };
  for (auto &testCase : testCases) {
    EXPECT_EQ(heap::kSmallestPairs(testCase.nums1, testCase.nums2, testCase.k), testCase.expected);
  }
}

TEST(HeapTest, findMaximizedCapital) {
  struct TestCase {
    int k;
    int w;
    std::vector<int> profits;
    std::vector<int> capital;
    int expected;
  };
  std::vector<TestCase> testCases = {
      {.k = 2, .w = 0, .profits = {1, 2, 3}, .capital = {0, 1, 1}, .expected = 4},
      {.k = 3, .w = 0, .profits = {1, 2, 3}, .capital = {0, 1, 2}, .expected = 6},
  };
  for (auto &testCase : testCases) {
    EXPECT_EQ(heap::findMaximizedCapital(testCase.k, testCase.w, testCase.profits, testCase.capital),
              testCase.expected);
  }
}

TEST(HeapTest, MedianFinder) {
  heap::MedianFinder mf;
  mf.addNum(1);
  EXPECT_EQ(mf.findMedian(), 1);
  mf.addNum(2);
  EXPECT_EQ(mf.findMedian(), 1.5);
  mf.addNum(3);
  EXPECT_EQ(mf.findMedian(), 2);
}
