#include "stack/stack.h"

#include <gtest/gtest.h>

TEST(StackTest, isValid) {
  struct TestCase {
    std::string input;
    bool expected;
  };

  std::vector<TestCase> test_cases = {
      {"()", true},   {"()[]{}", true}, {"(]", false}, {"([)]", false},
      {"{[]}", true}, {"(", false},     {"((", false}, {"))", false},
  };

  for (const auto &tc : test_cases) {
    EXPECT_EQ(stack::isValid(tc.input), tc.expected) << "Input: " << tc.input;
  }
}

TEST(StackTest, simplifyPath) {
  struct TestCase {
    std::string input;
    std::string expected;
  };

  std::vector<TestCase> test_cases = {
      {"/home/", "/home"},
      {"/../", "/"},
      {"//home/user/Documents/../Pictures", "/home/user/Pictures"},
      {"/home//foo/", "/home/foo"},
      {"/.../a/../b/c/../d/./", "/.../b/d"},
  };

  for (const auto &tc : test_cases) {
    EXPECT_EQ(stack::simplifyPath(tc.input), tc.expected) << "Input: " << tc.input;
  }
}

TEST(StackTest, MinStack) {
  stack::MinStack min_stack = {};
  min_stack.push(-3);
  min_stack.push(-3);
  min_stack.push(0);
  min_stack.push(-2);
  EXPECT_EQ(min_stack.getMin(), -3);
  min_stack.pop();
  EXPECT_EQ(min_stack.top(), 0);
  EXPECT_EQ(min_stack.getMin(), -3);
  min_stack.pop();
  min_stack.pop();
  EXPECT_EQ(min_stack.top(), -3);
  EXPECT_EQ(min_stack.getMin(), -3);
}

TEST(StackTest, evalRPN) {
  struct TestCase {
    std::vector<std::string> tokens;
    int expected;
  };

  std::vector<TestCase> test_cases = {
      {{"2", "1", "+", "3", "*"}, 9},
      {{"4", "13", "5", "/", "+"}, 6},
      {{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}, 22},
  };

  for (auto &&tc : test_cases) {
    EXPECT_EQ(stack::evalRPN(tc.tokens), tc.expected);
  }
}

TEST(StackTest, calculate) {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases = {
      {"3+2-2", 3}, {"3-2", 1}, {"3+5-2", 6}, {"31+53-26", 58}, {"(3+2)+2", 7},
  };

  for (auto &&tc : test_cases) {
    EXPECT_EQ(stack::calculate(tc.s), tc.expected);
  }
}
