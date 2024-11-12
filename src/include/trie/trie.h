#ifndef __TRIE_H__
#define __TRIE_H__

#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace trie {
class Trie {
 public:
  Trie() : children_(), isEnd_(false) {}

  void insert(std::string word);
  bool search(std::string word);
  bool startsWith(std::string prefix);
  friend std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words);

 private:
  std::unordered_map<char, Trie *> children_;
  bool isEnd_;
};

/// @brief A dictionary that supports adding words and searching for words with
/// dots '.' which can be matched with any letter.
class WordDictionary {
 public:
  WordDictionary() : children_(), isEnd_(false) {}

  /// @brief Add a word to the dictionary.
  /// @param word The word to add.
  void addWord(std::string word);
  void addWord(std::string_view word);
  /// @brief Search for a word in the dictionary. The word may contain dots '.'
  /// which can be matched with any letter.
  /// @param word The word to search for.
  /// @return True if the word is found, false otherwise.
  bool search(std::string word);
  bool search(std::string_view word);

 private:
  std::unordered_map<char, WordDictionary *> children_;
  bool isEnd_;
};

/// @brief Find all words on the board.
/// Each word must be constructed from letters of sequentially adjacent cells,
/// where adjacent cells are horizontally or vertically neighboring. The same
/// letter cell may not be used more than once in a word.
/// @param board The board to search on.
/// @param words The words to search for.
/// @return A vector of words found on the board.
/// constraints:
/// - m == board.length
///
/// - n == board[i].length
///
/// - 1 <= m, n <= 12
///
/// - 1 <= words.length <= 3 * 10^4
///
/// - 1 <= words[i].length <= 10
///
/// - board and words[i] consists only of lowercase English letters.
///
/// - All the strings of words are unique.
///
/// @note https://leetcode.com/problems/word-search-ii/
std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words);

}  // namespace trie

#endif  // __TRIE_H__
