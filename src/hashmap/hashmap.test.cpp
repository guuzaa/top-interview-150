#include "hashmap/hashmap.h"

#include <gtest/gtest.h>
#include <concepts>

namespace {
template <std::totally_ordered T>
std::vector<std::vector<T>> getSortedVectors(std::vector<std::vector<T>> vectors) {
  // Sort each inner vector
  for (auto &v : vectors) {
    std::sort(v.begin(), v.end());
  }
  // Sort the outer vector
  std::sort(vectors.begin(), vectors.end());
  return vectors;
}
}  // namespace

TEST(HashmapTest, canConstruct) {
  struct Case {
    std::string ransomNote;
    std::string magazine;
    bool expected;
  };
  std::vector<Case> cases = {
      {"a", "b", false},
      {"aa", "ab", false},
      {"aa", "aab", true},
      {"aab", "baa", true},
      {"fffbfg", "effjfggbffjdgbjjhhdegh", true},
      {"abcde", "fghij", false},
      {"abcde", "fhij", false},
  };
  for (const auto &c : cases) {
    EXPECT_EQ(hashmap::canConstruct(c.ransomNote, c.magazine), c.expected);
  }
}

TEST(HashmapTest, isIsomorphic) {
  struct Case {
    std::string s;
    std::string t;
    bool expected;
  };
  std::vector<Case> cases = {
      {"egg", "add", true},    {"foo", "bar", false},           {"paper", "title", true},
      {"badc", "baba", false}, {"bbbaaaba", "aaabbbba", false},
  };
  for (const auto &c : cases) {
    EXPECT_EQ(hashmap::isIsomorphic(c.s, c.t), c.expected);
  }
}

TEST(HashmapTest, wordPattern) {
  struct Case {
    std::string pattern;
    std::string s;
    bool expected;
  };

  std::vector<Case> cases = {
      {"abba", "dog cat cat dog", true},  {"abba", "dog cat cat fish", false}, {"aaaa", "dog cat cat dog", false},
      {"abba", "dog dog dog dog", false}, {"aaa", "aa aa aa aa", false},
  };
  for (auto &&c : cases) {
    EXPECT_EQ(hashmap::wordPattern(c.pattern, c.s), c.expected);
  }
}

TEST(HashmapTest, isAnagram) {
  struct Case {
    std::string s;
    std::string t;
    bool expected;
  };
  std::vector<Case> cases = {
      {"anagram", "nagaram", true},
      {"rat", "car", false},
      {"a", "ab", false},
      {"ab", "a", false},
  };
  for (const auto &c : cases) {
    EXPECT_EQ(hashmap::isAnagram(c.s, c.t), c.expected);
  }
}

TEST(HashmapTest, groupAnagrams) {
  struct Case {
    std::vector<std::string> strs;
    std::vector<std::vector<std::string>> expected;
  };

  std::vector<Case> cases = {
      {{"eat", "tea", "tan", "ate", "nat", "bat"}, {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}},
      {{""}, {{""}}},
      {{"a"}, {{"a"}}},
  };

  for (auto &&c : cases) {
    auto result = hashmap::groupAnagrams(c.strs);
    EXPECT_EQ(getSortedVectors(result), getSortedVectors(c.expected));
  }
}

TEST(HashmapTest, twoSum) {
  struct Case {
    std::vector<int> nums;
    int target;
    std::vector<int> expected;
  };
  std::vector<Case> cases = {
      {{2, 7, 11, 15}, 9, {0, 1}},
      {{3, 2, 4}, 6, {1, 2}},
      {{3, 3}, 6, {0, 1}},
  };
  for (auto &&c : cases) {
    EXPECT_EQ(hashmap::twoSum(c.nums, c.target), c.expected);
  }
}

TEST(HashmapTest, isHappy) {
  struct Case {
    int n;
    bool expected;
  };

  std::vector<Case> cases = {{19, true},      {2, false},          {1, true},          {100, true},
                             {1000000, true}, {2147483647, false}, {2147483647, false}};
  for (auto &&c : cases) {
    EXPECT_EQ(hashmap::isHappy(c.n), c.expected);
  }
}

TEST(HashmapTest, containsNearbyDuplicate) {
  struct Case {
    std::vector<int> nums;
    int k;
    bool expected;
  };
  std::vector<Case> cases = {
      {{1, 2, 3, 1}, 3, true}, {{1, 0, 1, 1}, 1, true},  {{1, 2, 3, 1, 2, 3}, 2, false},
      {{99, 99}, 2, true},     {{99, 10, 99}, 1, false}, {{1, 2, 3, 4, 5, 6, 7, 8, 9, 9}, 3, true},
  };
  for (auto &&c : cases) {
    EXPECT_EQ(hashmap::containsNearbyDuplicate(c.nums, c.k), c.expected);
  }
}

TEST(HashmapTest, longestConsecutive) {
  struct Case {
    std::vector<int> nums;
    int expected;
  };
  std::vector<Case> cases = {
      {{100, 4, 200, 1, 3, 2}, 4},
      {{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9},
      {{1, 2, 0, 1}, 3},
      {{}, 0},
      {{1}, 1},
      {{1, 1, 1}, 1},
      {{1, 2, 3, 4, 5}, 5},
      {{5, 4, 3, 2, 1}, 5},
      {{1, 3, 5, 7, 9}, 1},
      {{-5, -4, -3, -2, -1}, 5},
      {{-1, 0, 1}, 3},
      // {{2147483647, -2147483648}, 1}
  };
  for (auto &&c : cases) {
    EXPECT_EQ(hashmap::longestConsecutive(c.nums), c.expected);
  }
}
