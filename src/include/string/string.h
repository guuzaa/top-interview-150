#ifndef __STRING_H__
#define __STRING_H__

#include <string>
#include <vector>

namespace string {

/// @brief Convert a Roman numeral to an integer.
/// @param s The Roman numeral.
/// @return The integer.
///
/// constraints
/// - 1 <= s.length <= 15
///
/// - s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
///
/// - It is guaranteed that s is a valid Roman numeral in the range [1, 3999].
///
/// @note https://leetcode.com/problems/roman-to-integer/
int romanToInt(std::string s);

/// @brief Convert an integer to a Roman numeral.
/// @param num The integer.
/// @return The Roman numeral.
///
/// constraints
///
/// - 1 <= num <= 3999
///
/// @note https://leetcode.com/problems/integer-to-roman/
std::string intToRoman(int num);

/// @brief Given a string s consisting of words and spaces, return the length of the last word in the string.
/// @param s The string.
/// @return The length of the last word.
///
/// constraints
/// - 1 <= s.length <= 10^4
///
/// - s consists of only English letters and spaces ' '.
///
/// - There will be at least one word in s.
///
/// @note https://leetcode.com/problems/length-of-last-word/
int lengthOfLastWord(std::string s);

/// @brief Write a function to find the longest common prefix string amongst an array of strings.
/// @param strs The array of strings.
/// @return The longest common prefix string.
///
/// constraints
/// - 1 <= strs.length <= 200
///
/// - 0 <= strs[i].length <= 200
///
/// - strs[i] consists of only English letters.
///
/// @note https://leetcode.com/problems/longest-common-prefix/
std::string longestCommonPrefix(std::vector<std::string> &strs);

/// @brief Given a string s, reverse the order of the words.
/// @param s The string.
/// @return The string with the words reversed and concatenated by a single space.
///
/// constraints
/// - 1 <= s.length <= 10^4
///
/// - s contains English letters (upper-case and lower-case), digits, and spaces ' '.
///
/// - There is at least one word in s.
///
/// @note https://leetcode.com/problems/reverse-words-in-a-string/
std::string reverseWords(std::string s);

/// @brief Given a string s and an integer numRows, return the converted in zigzag pattern string given a number of
/// rows.
/// @param s The string.
/// @param numRows The number of rows.
/// @return The converted in zigzag pattern string.
///
/// constraints
/// - 1 <= s.length <= 10^5
///
/// - s consists of English letters (lower-case and upper-case), ',' and '.'.
///
/// - 1 <= numRows <= 1000
///
/// @note https://leetcode.com/problems/zigzag-conversion/
std::string convert(std::string s, int numRows);

/// @brief Implement strStr().
/// @param haystack The string to search in.
/// @param needle The string to search for.
/// @return The index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
///
/// constraints
/// - 1 <= haystack.length, needle.length <= 10^4
///
/// - haystack and needle consist of only lowercase English letters.
///
/// @note https://leetcode.com/problems/implement-strstr/
int strStr(std::string haystack, std::string needle);

/// @brief Given an array of strings words and a width maxWidth, format the text such that each line has exactly
/// maxWidth characters and is fully (left and right) justified.
/// @param words The array of strings.
/// @param maxWidth The width.
/// @return The array of strings.
///
/// constraints
/// - 1 <= words.length <= 300
///
/// - 1 <= words[i].length <= 20
///
/// - words[i] consists of only English letters and symbols.
///
/// - 1 <= maxWidth <= 100
///
/// @note https://leetcode.com/problems/text-justification/
std::vector<std::string> fullJustify(std::vector<std::string> &words, int maxWidth);
}  // namespace string

#endif
