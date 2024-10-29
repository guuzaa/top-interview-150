#ifndef __HASHMAP_HASHMAP_H__
#define __HASHMAP_HASHMAP_H__

#include <string>
#include <vector>

namespace hashmap {
/// @brief Given two strings ransomNote and magazine, return true if ransomNote
/// can be constructed by using the letters from magazine and false otherwise.
/// Each letter in magazine can only be used once in ransomNote.
///
/// @param ransomNote The string to be constructed.
/// @param magazine The string to be used to construct ransomNote.
/// @return True if ransomNote can be constructed by using the letters from
/// magazine, false otherwise.
///
/// constraints:
/// - 1 <= ransomNote.length, magazine.length <= 10^5
///
/// - ransomNote and magazine consist of lowercase English letters.
///
/// @note https://leetcode.com/problems/ransom-note/
bool canConstruct(std::string ransomNote, std::string magazine);

/// @brief Given two strings s and t, determine if they are isomorphic.
///
/// Two strings s and t are isomorphic if the characters in s can be replaced to
/// get t while preserving the order of characters.
///
/// @param s The first string.
/// @param t The second string.
/// @return True if s and t are isomorphic, false otherwise.
///
/// constraints:
///
/// - 1 <= s.length <= 5 * 10^4
///
/// - t.length == s.length
///
/// - s and t consist of any valid ascii character.
///
/// @note https://leetcode.com/problems/isomorphic-strings/
bool isIsomorphic(std::string s, std::string t);

/// @brief Given a pattern and a string s, find if s follows the same pattern.
///
/// @param pattern The pattern to check against.
/// @param s The string to check.
/// @return True if s follows the same pattern as pattern, false otherwise.
///
/// constraints:
///
/// - 1 <= pattern.length <= 300
///
/// - pattern contains only lower-case English letters.
///
/// - 1 <= s.length <= 3000
///
/// - s contains only lowercase English letters and spaces ' '.
///
/// - s does not contain any leading or trailing spaces.
///
/// @note https://leetcode.com/problems/word-pattern/
bool wordPattern(std::string pattern, std::string s);

/// @brief Given two strings s and t, return true if t is an anagram of s, and
/// false otherwise.
///
/// @param s The first string.
/// @param t The second string.
/// @return True if t is an anagram of s, false otherwise.
///
/// constraints:
///
/// - 1 <= s.length, t.length <= 5 * 10^4
///
/// - s and t consist of lowercase English letters.
///
/// @note https://leetcode.com/problems/valid-anagram/
bool isAnagram(std::string s, std::string t);

/// @brief Given an array of strings strs, group the anagrams together. You can
/// return the answer in any order.
///
/// @param strs The array of strings.
/// @return The array of grouped anagrams.
///
/// constraints:
///
/// - 1 <= strs.length <= 10^4
///
/// - 0 <= strs[i].length <= 100
///
/// - strs[i] consists of lowercase English letters.
///
/// @note https://leetcode.com/problems/group-anagrams/
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs);

/// @brief Given an array of integers nums and an integer target, return
/// indices of the two numbers such that they add up to target.
///
/// @param nums The array of integers.
/// @param target The target sum.
/// @return The indices of the two numbers such that they add up to target.
///
/// constraints:
///
/// - 2 <= nums.length <= 10^4
///
/// - -10^9 <= nums[i] <= 10^9
///
/// - -10^9 <= target <= 10^9
///
/// - Only one valid answer exists.
///
/// @note https://leetcode.com/problems/two-sum/
std::vector<int> twoSum(std::vector<int> &nums, int target);

/// @brief Write an algorithm to determine if a number n is happy.
///
/// A happy number is a number defined by the following process:
///
/// - Starting with any positive integer, replace the number by the sum of the
/// squares of its digits.
///
/// - Repeat the process until the number equals 1 (where it will stay), or it
/// loops endlessly in a cycle which does not include 1.
///
/// - Those numbers for which this process ends in 1 are happy.
///
/// @param n The number to check.
/// @return True if n is a happy number, false otherwise.
///
/// constraints:
///
/// - 1 <= n <= 2^31 - 1
///
/// @note https://leetcode.com/problems/happy-number/
bool isHappy(int n);

/// @brief Given an integer array nums and an integer k, return true if there are
/// two distinct indices i and j in the array such that nums[i] == nums[j] and
/// abs(i - j) <= k.
///
/// @param nums The array of integers.
/// @param k The maximum distance between the indices.
/// @return True if there are two distinct indices i and j in the array such
/// that nums[i] == nums[j] and abs(i - j) <= k, false otherwise.
///
/// constraints:
///
/// - 1 <= nums.length <= 10^5
///
/// - -10^9 <= nums[i] <= 10^9
///
/// - 0 <= k <= 10^5
///
/// @note https://leetcode.com/problems/contains-duplicate-ii/
bool containsNearbyDuplicate(std::vector<int> &nums, int k);

/// @brief Given an unsorted array of integers nums, return the length of the
/// longest consecutive elements sequence.
///
/// @param nums The array of integers.
/// @return The length of the longest consecutive elements sequence.
///
/// constraints:
///
/// - 0 <= nums.length <= 10^5
///
/// - -10^9 <= nums[i] <= 10^9
///
/// @note https://leetcode.com/problems/longest-consecutive-sequence/
int longestConsecutive(std::vector<int> &nums);

}  // namespace hashmap

#endif  // __HASHMAP_HASHMAP_H__
