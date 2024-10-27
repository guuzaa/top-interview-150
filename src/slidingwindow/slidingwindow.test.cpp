#include "slidingwindow/slidingwindow.h"

#include <gtest/gtest.h>

TEST(SlidingWindowTest, minSubArrayLen) {
  struct Case {
    std::vector<int> nums;
    int target;
    int expected;
  };

  std::vector<Case> cases = {{{1, 2, 3, 4, 5}, 11, 3},   {{1, 2, 3, 4, 5}, 15, 5}, {{1, 2, 3, 4, 5}, 5, 1},
                             {{1, 2, 3, 4, 5}, 10, 3},   {{1, 2, 3, 4, 5}, 1, 1},  {{2, 3, 1, 2, 4, 3}, 7, 2},
                             {{2, 3, 1, 2, 4, 3}, 4, 1}, {{1, 1, 1, 1, 1}, 11, 0}, {{1, 4, 4}, 4, 1}};

  for (auto &&c : cases) {
    EXPECT_EQ(slidingwindow::minSubArrayLen(c.target, c.nums), c.expected);
  }
}

TEST(SlidingWindowTest, lengthOfLongestSubstring) {
  struct Case {
    std::string s;
    int expected;
  };

  slidingwindow::lengthOfLongestSubstring("pwwkew");

  std::vector<Case> cases = {{"abcabcbb", 3}, {"bbbbb", 1}, {"pwwkew", 3}, {"", 0},     {"a", 1},      {"au", 2},
                             {"aab", 2},      {"dvdf", 3},  {"anviaj", 5}, {"abba", 2}, {"tmmzuxt", 5}};

  for (auto &&c : cases) {
    EXPECT_EQ(slidingwindow::lengthOfLongestSubstring(c.s), c.expected);
  }
}

TEST(SlidingWindowTest, findSubstring) {
  struct Case {
    std::string s;
    std::vector<std::string> words;
    std::vector<int> expected;
  };

  std::vector<Case> cases = {{"barfoothefoobarman", {"foo", "bar"}, {0, 9}},
                             {"wordgoodgoodgoodbestword", {"word", "good", "best", "word"}, {}},
                             {"barfoofoobarthefoobarman", {"bar", "foo", "the"}, {6, 9, 12}},
                             {"wordgoodgoodgoodbestword", {"word", "good", "best", "good"}, {8}},
                             {"foobarfoobar", {"foo", "bar"}, {0, 3, 6}},
                             {"a", {"a"}, {0}},
                             {"x", {"x", "x"}, {}},
                             {"barfoo", {"foo"}, {3}},
                             {"foobar", {"foo"}, {0}},
                             {"ab", {"a"}, {0}}};

  for (auto &&c : cases) {
    EXPECT_EQ(slidingwindow::findSubstring(c.s, c.words), c.expected);
  }
}

TEST(SlidingWindowTest, minWindow) {
  struct Case {
    std::string s;
    std::string t;
    std::string expected;
  };

  std::vector<Case> cases = {{"ADOBECODEBANC", "ABC", "BANC"},
                             {"a", "a", "a"},
                             {"a", "aa", ""},
                             {"aa", "aa", "aa"},
                             {"aaaaaaaaaa", "aaaa", "aaaa"},
                             {"ADOBECODEBANC", "ABCC", "CODEBANC"},
                             {"zxycbaabcdwwww", "abc", "cba"},
                             {"aaabbaaba", "abb", "abb"},
                             {"mississippi", "issi", "issi"},
                             {"thequickbrownfoxjumpsoverthelazydog", "god", "dog"}};

  for (auto &&c : cases) {
    EXPECT_EQ(slidingwindow::minWindow(c.s, c.t), c.expected);
  }
}
