#include <gtest/gtest.h>

#include "math/math.h"

TEST(math, isPalindrome) {
  struct TestCase {
    int number;
    bool expected;
  };
  std::vector<TestCase> test_cases = {
      {121, true},
      {-121, false},
      {10, false},
      {-101, false},
      {12321, true},
      {1234567899, false},
      {std::numeric_limits<int>::max(), false},
      {std::numeric_limits<int>::min(), false},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(math::isPalindrome(test_case.number), test_case.expected);
  }
}

TEST(math, plusOne) {
  struct TestCase {
    std::vector<int> digits;
    std::vector<int> expected;
  };
  std::vector<TestCase> test_cases = {
      {{1, 2, 3}, {1, 2, 4}},
      {{4, 3, 2, 1}, {4, 3, 2, 2}},
      {{9}, {1, 0}},
  };
  for (auto &test_case : test_cases) {
    EXPECT_EQ(math::plusOne(test_case.digits), test_case.expected);
  }
}

TEST(math, trailingZeroes) {
  struct TestCase {
    int n;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {3, 0}, {5, 1}, {0, 0}, {10000, 2499}, {100000, 24999},
  };
  for (const auto &test_case : test_cases) {
    EXPECT_EQ(math::trailingZeroes(test_case.n), test_case.expected);
  }
}

TEST(math, mySqrt) {
  struct TestCase {
    int x;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {4, 2}, {8, 2}, {16, 4}, {1, 1}, {0, 0}, {std::numeric_limits<int>::max(), 46340},
  };
  for (const auto &test_case : test_cases) {
    EXPECT_EQ(math::mySqrt(test_case.x), test_case.expected);
  }
}

TEST(math, myPow) {
  struct TestCase {
    double x;
    int n;
    double expected;
  };
  std::vector<TestCase> test_cases = {
      {2.0, 10, 1024.0},
      {2.1, 3, 9.261},
      {2.0, -2, 0.25},
      {1.0, -2147483648, 1.0},
  };
  for (const auto &test_case : test_cases) {
    EXPECT_DOUBLE_EQ(math::myPow(test_case.x, test_case.n), test_case.expected);
  }
}

TEST(math, maxPoints) {
  struct TestCase {
    std::vector<std::vector<int>> points;
    int expected;
  };
  std::vector<TestCase> test_cases = {{{{1, 1}, {2, 2}, {3, 3}}, 3},
                                      {{{1, 1}, {2, 2}}, 2},
                                      {{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}}, 4},
                                      {{{0, 0}}, 1}};
  for (auto &test_case : test_cases) {
    EXPECT_EQ(math::maxPoints(test_case.points), test_case.expected);
  }
}
