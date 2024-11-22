#include "bit/bit.h"
#include <gtest/gtest.h>

TEST(BitTest, AddBinaryTest) {
  struct Case {
    std::string a;
    std::string b;
    std::string want;
  };
  std::vector<Case> cases = {{"11", "1", "100"}, {"1010", "1011", "10101"}, {"1111", "1111", "11110"}};
  for (auto &c : cases) {
    std::string result = bit::addBinary(c.a, c.b);
    EXPECT_EQ(result, c.want);
  }
}

TEST(BitTest, ReverseBitsTest) {
  struct Case {
    uint32_t n;
    uint32_t want;
  };
  std::vector<Case> cases = {{43261596, 964176192}, {4294967293, 3221225471}};
  for (auto &c : cases) {
    uint32_t result = bit::reverseBits(c.n);
    EXPECT_EQ(result, c.want);
  }
}

TEST(BitTest, HammingWeightTest) {
  struct Case {
    uint32_t n;
    int want;
  };
  std::vector<Case> cases = {{11, 3}, {128, 1}, {4294967293, 31}};
  for (auto &c : cases) {
    int result = bit::hammingWeight(c.n);
    EXPECT_EQ(result, c.want);
  }
}

TEST(BitTest, SingleNumberTest) {
  struct Case {
    std::vector<int> nums;
    int want;
  };
  std::vector<Case> cases = {{{2, 2, 1}, 1}, {{4, 1, 2, 1, 2}, 4}, {{1}, 1}};
  for (auto &c : cases) {
    int result = bit::singleNumber(c.nums);
    EXPECT_EQ(result, c.want);
  }
}

TEST(BitTest, SingleNumber2Test) {
  struct Case {
    std::vector<int> nums;
    int want;
  };
  std::vector<Case> cases = {{{2, 2, 3, 2}, 3}, {{0, 1, 0, 1, 0, 1, 99}, 99}};
  for (auto &c : cases) {
    int result = bit::singleNumber2(c.nums);
    EXPECT_EQ(result, c.want);
  }
}

TEST(BitTest, RangeBitwiseAndTest) {
  struct Case {
    int left;
    int right;
    int want;
  };
  std::vector<Case> cases = {{5, 7, 4}, {0, 1, 0}, {1, 2147483647, 0}};
  for (auto &c : cases) {
    int result = bit::rangeBitwiseAnd(c.left, c.right);
    EXPECT_EQ(result, c.want);
  }
}