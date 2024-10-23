#include "string/string.h"

#include <gtest/gtest.h>

TEST(StringTest, RomanToInt) {
  struct Case {
    std::string roman;
    int expected;
  };
  std::vector<Case> cases = {{"III", 3}, {"IV", 4}, {"IX", 9}, {"XL", 40}, {"LVIII", 58}, {"MCMXCIV", 1994}};
  for (auto &c : cases) {
    EXPECT_EQ(string::romanToInt(c.roman), c.expected);
  }
}

TEST(StringTest, IntToRoman) {
  struct Case {
    int num;
    std::string expected;
  };
  std::vector<Case> cases = {{3, "III"},           {4, "IV"},        {9, "IX"}, {40, "XL"}, {58, "LVIII"},
                             {3749, "MMMDCCXLIX"}, {1994, "MCMXCIV"}};
  for (auto &c : cases) {
    EXPECT_EQ(string::intToRoman(c.num), c.expected);
  }
}

TEST(StringTest, LengthOfLastWord) {
  struct Case {
    std::string s;
    int expected;
  };
  std::vector<Case> cases = {{"Hello World", 5},
                             {"   fly me   to   the moon  ", 4},
                             {"luffy is still joyboy", 6},
                             {"a", 1},
                             {"", 0},
                             {"   ", 0},
                             {"Hello", 5},
                             {"Hello    ", 5},
                             {"    Hello", 5},
                             {"Hello World!   ", 6},
                             {"This is a longer sentence with multiple words", 5}};
  for (auto &c : cases) {
    EXPECT_EQ(string::lengthOfLastWord(c.s), c.expected);
  }
}

TEST(StringTest, LongestCommonPrefix) {
  struct Case {
    std::vector<std::string> strs;
    std::string expected;
  };
  std::vector<Case> cases = {{{"flower", "flow", "flight"}, "fl"},
                             {{"dog", "racecar", "car"}, ""},
                             {{"interspecies", "interstellar", "interstate"}, "inters"},
                             {{"throne", "throne"}, "throne"},
                             {{"c", "c"}, "c"},
                             {{"", ""}, ""},
                             {{"prefix", "prefix", "prefix"}, "prefix"},
                             {{"abc", "abcd", "abcde", "abcdef"}, "abc"},
                             {{"spot", "spotty", "spotted"}, "spot"}};
  for (auto &&c : cases) {
    EXPECT_EQ(string::longestCommonPrefix(c.strs), c.expected);
  }
}

TEST(StringTest, ReverseWords) {
  struct Case {
    std::string s;
    std::string expected;
  };
  std::vector<Case> cases = {{"the sky is blue", "blue is sky the"},
                             {"  hello world  ", "world hello"},
                             {"a", "a"},
                             {"  Bob    Loves  Alice   ", "Alice Loves Bob"},
                             {"Alice does not even like Bob", "Bob like even not does Alice"},
                             {"", ""},
                             {"   ", ""},
                             {"This   is   a   test", "test a is This"},
                             {"Reverse these    words", "words these Reverse"},
                             {"   Spaces   at   both   ends  ", "ends both at Spaces"}};
  for (auto &&c : cases) {
    EXPECT_EQ(string::reverseWords(c.s), c.expected);
  }
}

TEST(StringTest, Convert) {
  struct Case {
    std::string s;
    int numRows;
    std::string expected;
  };
  std::vector<Case> cases = {{"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"},
                             {"PAYPALISHIRING", 4, "PINALSIGYAHRPI"},
                             {"Hello", 10, "Hello"},
                             {"A", 1, "A"}};
  for (auto &&c : cases) {
    EXPECT_EQ(string::convert(c.s, c.numRows), c.expected);
  }
}

TEST(StringTest, StrStr) {
  struct Case {
    std::string haystack;
    std::string needle;
    int expected;
  };
  std::vector<Case> cases = {{"hello", "ll", 2},
                             {"aaaaa", "bba", -1},
                             {"mississippi", "issip", 4},
                             {"leetcode", "leeto", -1},
                             {"haystack", "needle", -1},
                             {"needle", "needle", 0},
                             {"a", "a", 0},
                             {"aaa", "aaaa", -1}};
  for (auto &&c : cases) {
    EXPECT_EQ(string::strStr(c.haystack, c.needle), c.expected);
  }
}

TEST(StringTest, FullJustify) {
  struct Case {
    std::vector<std::string> words;
    int maxWidth;
    std::vector<std::string> expected;
  };

  std::vector<Case> cases = {{{"This", "is", "an", "example", "of", "text", "justification."},
                              16,
                              {"This    is    an", "example  of text", "justification.  "}},
                             {{"What", "must", "be", "acknowledgment", "shall", "be"},
                              16,
                              {"What   must   be", "acknowledgment  ", "shall be        "}},
                             {{"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to",
                               "a", "computer.", "Art", "is", "everything", "else", "we", "do"},
                              20,
                              {"Science  is  what we", "understand      well", "enough to explain to",
                               "a  computer.  Art is", "everything  else  we", "do                  "}},
                             {{"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"},
                              10,
                              {"The  quick", "brown  fox", "jumps over", "the   lazy", "dog       "}}};
  for (auto &&c : cases) {
    EXPECT_EQ(string::fullJustify(c.words, c.maxWidth), c.expected);
  }
}
