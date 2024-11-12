#include "trie/trie.h"

#include <functional>

namespace trie {

void Trie::insert(std::string word) {
  auto curr = this;
  for (char c : word) {
    if (auto it = curr->children_.find(c); it == curr->children_.end()) {
      curr->children_[c] = new Trie();
    }
    curr = curr->children_[c];
  }
  curr->isEnd_ = true;
}

bool Trie::search(std::string word) {
  auto curr = this;
  for (char c : word) {
    auto it = curr->children_.find(c);
    if (it == curr->children_.end()) {
      return false;
    }
    curr = it->second;
  }
  return curr->isEnd_;
}

bool Trie::startsWith(std::string prefix) {
  auto curr = this;
  for (char c : prefix) {
    auto it = curr->children_.find(c);
    if (it == curr->children_.end()) {
      return false;
    }
    curr = it->second;
  }
  return true;
}

void WordDictionary::addWord(std::string word) {
  auto curr = this;
  for (char c : word) {
    if (auto it = curr->children_.find(c); it == curr->children_.end()) {
      curr->children_[c] = new WordDictionary();
    }
    curr = curr->children_[c];
  }
  curr->isEnd_ = true;
}

void WordDictionary::addWord(std::string_view word) {
  auto curr = this;
  for (char c : word) {
    if (auto it = curr->children_.find(c); it == curr->children_.end()) {
      curr->children_[c] = new WordDictionary();
    }
    curr = curr->children_[c];
  }
  curr->isEnd_ = true;
}

bool WordDictionary::search(std::string word) {
  auto curr = this;
  for (size_t i = 0; i < word.size(); ++i) {
    char ch = word[i];
    if (ch == '.') {
      for (auto &[_, node] : curr->children_) {
        // TODO substr is O(n)
        if (node->search(word.substr(i + 1))) {
          return true;
        }
      }
      return false;
    } else {
      auto it = curr->children_.find(ch);
      if (it == curr->children_.end()) {
        return false;
      }
      curr = it->second;
    }
  }
  return curr->isEnd_;
}

bool WordDictionary::search(std::string_view word) {
  auto curr = this;
  for (size_t i = 0; i < word.size(); ++i) {
    char ch = word[i];
    if (ch == '.') {
      for (auto &[_, node] : curr->children_) {
        if (node->search(word.substr(i + 1))) {
          return true;
        }
        return false;
      }
    } else {
      auto it = curr->children_.find(ch);
      if (it == curr->children_.end()) {
        return false;
      }
      curr = it->second;
    }
  }
  return curr->isEnd_;
}

std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words) {
  // Build Trie
  Trie *root = new Trie();
  for (const auto &word : words) {
    root->insert(word);
  }

  std::vector<std::string> result;
  int m = static_cast<int>(board.size());
  int n = static_cast<int>(board[0].size());

  std::function<void(int, int, Trie *, std::string)> dfs = [&](int i, int j, Trie *node, std::string current) {
    // Get current character and mark as visited
    char c = board[i][j];
    board[i][j] = '#';

    // Check if this character exists in current trie node
    if (auto it = node->children_.find(c); it != node->children_.end()) {
      Trie *next = it->second;
      current += c;

      // If we've found a word, add to result
      if (next->isEnd_) {
        result.push_back(current);
        next->isEnd_ = false;  // Mark as found to avoid duplicates
      }

      // Explore all 4 directions
      constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
      for (auto [dx, dy] : dirs) {
        int ni = i + dx;
        int nj = j + dy;
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] != '#') {
          dfs(ni, nj, next, current);
        }
      }
    }

    // Restore the board
    board[i][j] = c;
  };

  // Start DFS from each cell
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      dfs(i, j, root, "");
    }
  }

  return result;
}

}  // namespace trie
