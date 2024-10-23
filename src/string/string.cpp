#include "string/string.h"
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <vector>

namespace string {

int romanToInt(std::string s) {
  const std::unordered_map<char, int> roman_map = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                                   {'C', 100}, {'D', 500}, {'M', 1000}};
  int result = 0;
  int len = static_cast<int>(s.size());
  for (int i = 0; i < len; ++i) {
    if (i + 1 < len && roman_map.at(s[i]) < roman_map.at(s[i + 1])) {
      result -= roman_map.at(s[i]);
    } else {
      result += roman_map.at(s[i]);
    }
  }
  return result;
}

std::string intToRoman(int num) {
  std::string result;
  std::vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  std::vector<std::string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

  for (int i = 0; i < static_cast<int>(values.size()); ++i) {
    while (num >= values[i]) {
      result += symbols[i];
      num -= values[i];
    }
  }

  return result;
}

int lengthOfLastWord(std::string s) {
  int len = static_cast<int>(s.size());
  int last_word_len = 0;
  for (int i = len - 1; i >= 0; --i) {
    if (s[i] == ' ') {
      if (last_word_len > 0) {
        break;
      }
    } else {
      ++last_word_len;
    }
  }
  return last_word_len;
}

std::string longestCommonPrefix(std::vector<std::string> &strs) {
  std::string prefix = {};
  for (int j = 0; j < static_cast<int>(strs[0].size()); ++j) {
    char c = strs[0][j];
    if (std::any_of(strs.begin() + 1, strs.end(), [j, c](const auto &s) { return s[j] != c; })) {
      return prefix;
    }
    prefix += c;
  }
  return prefix;
}

std::string reverseWords(std::string s) {
  std::vector<std::string> words;
  std::istringstream iss(s);
  std::string word;

  while (iss >> word) {
    words.push_back(word);
  }

  std::string result;
  int len = static_cast<int>(words.size());
  for (int i = len - 1; i >= 0; --i) {
    if (i < len - 1) {
      result += " ";
    }
    result += words[i];
  }

  return result;
}

std::string convert(std::string s, int numRows) {
  int len = static_cast<int>(s.size());
  if (numRows == 1 || numRows >= len) {
    return s;
  }

  std::vector<std::string> rows(numRows);
  int current_row = 0;
  bool going_down = false;
  for (char c : s) {
    rows[current_row] += c;
    if (current_row == 0 || current_row == numRows - 1) {
      going_down = !going_down;
    }
    current_row += going_down ? 1 : -1;
  }

  std::string result;
  result.reserve(len);
  for (const auto &row : rows) {
    result.append(row);
  }
  return result;
}

int strStr(std::string haystack, std::string needle) {
  int len_haystack = static_cast<int>(haystack.size());
  int len_needle = static_cast<int>(needle.size());
  for (int i = 0; i <= len_haystack - len_needle; ++i) {
    for (int j = 0; j < len_needle; ++j) {
      if (haystack[i + j] != needle[j]) {
        break;
      }
      if (j == len_needle - 1) {
        return i;
      }
    }
  }
  return -1;
}

std::vector<std::string> fullJustify(std::vector<std::string> &words, int maxWidth) {
  std::vector<std::string> result;
  int n = static_cast<int>(words.size());
  int i = 0;
  while (i < n) {
    int j = i;
    int lineLength = 0;

    // Find words that fit in this line
    while (j < n && lineLength + static_cast<int>(words[j].length()) + (j - i) <= maxWidth) {
      lineLength += static_cast<int>(words[j].length());
      ++j;
    }

    int wordsInLine = j - i;
    int spaces = maxWidth - lineLength;

    std::string line;
    line.reserve(maxWidth);
    if (wordsInLine == 1 || j == n) {
      for (int k = i; k < j; ++k) {
        line.append(words[k]);
        if (k < j - 1) {
          line += " ";
          --spaces;
        }
      }
      line.append(spaces, ' ');
    } else {
      int spacesBetweenWords = spaces / (wordsInLine - 1);
      int extraSpaces = spaces % (wordsInLine - 1);

      for (int k = i; k < j; ++k) {
        line.append(words[k]);
        if (k < j - 1) {
          int spacesToAdd = spacesBetweenWords + (extraSpaces > 0 ? 1 : 0);
          line.append(spacesToAdd, ' ');
          --extraSpaces;
        }
      }
    }

    result.push_back(std::move(line));
    i = j;
  }

  return result;
}
}  // namespace string
