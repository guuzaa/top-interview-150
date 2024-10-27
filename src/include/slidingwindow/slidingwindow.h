#ifndef __SLIDINGWINDOW_H__
#define __SLIDINGWINDOW_H__

#include <string>
#include <vector>

namespace slidingwindow {

/// @brief Given an array of positive integers nums and a positive integer target,
/// return the minimal length of a contiguous subarray of which the sum is greater than or equal to target.
/// If there isn't one, return 0 instead.
/// @param target The target sum.
/// @param nums The array of positive integers.
/// @return The minimal length of a contiguous subarray of which the sum is greater than or equal to target.
///
/// constraints
///
/// - 1 <= target <= 10^9
///
/// - 1 <= nums.length <= 10^5
///
/// - 1 <= nums[i] <= 10^4
///
/// @note https://leetcode.com/problems/minimum-size-subarray-sum/
int minSubArrayLen(int target, std::vector<int> &nums);

/// @brief Given a string s, find the length of the longest substring without repeating characters.
/// @param s The string to find the longest substring without repeating characters.
/// @return The length of the longest substring without repeating characters.
///
/// constraints
///
/// - 0 <= s.length <= 5 * 10^4
///
/// - s consists of English letters, digits, symbols and spaces.
///
/// @note https://leetcode.com/problems/longest-substring-without-repeating-characters/
int lengthOfLongestSubstring(std::string s);

/// @brief You are given a string s and an array of strings words. All the strings of words are of the same length.
/// @param s The string to find the indices of the starting indices of substrings.
/// @param words The array of strings to find in the string.
/// @return The indices of the starting indices of substrings in `s` that are concatenations of all strings from
/// `words`.
///
/// constraints
///
/// - 1 <= s.length <= 10^4
///
/// - 1 <= words.length <= 5000
///
/// - 1 <= words[i].length <= 30
///
/// @note https://leetcode.com/problems/substring-with-concatenation-of-all-words/
std::vector<int> findSubstring(std::string s, std::vector<std::string> &words);

/// @brief Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such
/// that every character in t (including duplicates) is included in the window. If there is no such substring,
/// return the empty string "".
/// @param s The string to find the minimum window substring.
/// @param t The string to find in the string.
/// @return The minimum window substring of s such that every character in t (including duplicates) is included in
/// the window.
///
/// constraints
///
/// - 1 <= s.length, t.length <= 10^5
///
/// @note https://leetcode.com/problems/minimum-window-substring/
std::string minWindow(std::string s, std::string t);

}  // namespace slidingwindow

#endif  // __SLIDINGWINDOW_H__
