#include "trie/trie.h"

#include <gtest/gtest.h>

using namespace std::string_literals;

TEST(TrieTest, trie) {
  trie::Trie trie;
  trie.insert("apple");
  EXPECT_TRUE(trie.search("apple"));
  EXPECT_FALSE(trie.search("app"));
  EXPECT_TRUE(trie.startsWith("app"));
  trie.insert("app");
  EXPECT_TRUE(trie.search("app"));
}

TEST(WordDictionaryTest, wordDictionary) {
  trie::WordDictionary wordDictionary;
  wordDictionary.addWord("bad"s);
  wordDictionary.addWord("dad"s);
  wordDictionary.addWord("mad"s);
  EXPECT_FALSE(wordDictionary.search("pad"s));
  EXPECT_TRUE(wordDictionary.search("bad"s));
  EXPECT_TRUE(wordDictionary.search(".ad"s));
  EXPECT_FALSE(wordDictionary.search("z.."s));
  EXPECT_TRUE(wordDictionary.search("b.."s));
}

TEST(WordDictionaryTest, wordDictionary1) {
  trie::WordDictionary wordDictionary;
  wordDictionary.addWord("a"s);
  wordDictionary.addWord("a"s);
  EXPECT_TRUE(wordDictionary.search("."s));
  EXPECT_TRUE(wordDictionary.search("a"s));
  EXPECT_FALSE(wordDictionary.search("aa"s));
  EXPECT_TRUE(wordDictionary.search("a"s));
  EXPECT_FALSE(wordDictionary.search(".a"s));
  EXPECT_FALSE(wordDictionary.search("a."s));
}

TEST(FindWordsTest, findWords) {
  struct TestCase {
    std::vector<std::vector<char>> board;
    std::vector<std::string> words;
    std::vector<std::string> expected;
  };
  std::vector<TestCase> testCases = {
      {
          {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}},
          {"oath", "pea", "eat", "rain"},
          {"oath", "eat"},
      },
      {
          {{'a', 'b'}, {'c', 'd'}},
          {"abcb"},
          {},
      },
  };
  for (auto &testCase : testCases) {
    auto result = trie::findWords(testCase.board, testCase.words);
    EXPECT_EQ(result, testCase.expected);
  }
}
