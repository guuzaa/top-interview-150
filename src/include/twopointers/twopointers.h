#ifndef TWOPOINTERS_H
#define TWOPOINTERS_H

#include <string>
#include <vector>

namespace twopointers {
/// @brief Check if a string is a palindrome.
/// @param s The string.
/// @return True if the string is a palindrome, false otherwise.
///
/// constraints
///
/// - 1 <= s.length <= 2 * 10^5
///
/// - s consists of printable ASCII characters.
///
/// @note https://leetcode.com/problems/valid-palindrome/
bool isPalindrome(std::string s);

/// @brief Check if s is a subsequence of t.
/// A subsequence of a string is a sequence of characters that can be derived from another string by deleting some or
/// no characters without disturbing the relative positions of the remaining characters.
/// @param s The subsequence string.
/// @param t The target string.
/// @return True if s is a subsequence of t, false otherwise.
///
/// constraints
///
/// - 0 <= s.length <= 100
///
/// - 0 <= t.length <= 10^4
///
/// - s and t consist only of lowercase English letters.
///
/// @note https://leetcode.com/problems/is-subsequence/
bool isSubsequence(std::string s, std::string t);

/// @brief Find two numbers in an array sorted in non-decreasing order that add up to a target value.
/// @param nums The sorted 1-indexed array.
/// @param target The target value.
/// @return The indices of the two numbers.
///
/// constraints
///
/// - 2 <= nums.length <= 3 * 10^4
///
/// - -1000 <= nums[i] <= 1000
///
/// - nums is sorted in non-decreasing order.
///
/// - -1000 <= target <= 1000
///
/// @note https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
std::vector<int> twoSum(std::vector<int> &nums, int target);

/// @brief Find the maximum area of water that can be contained between two lines on a graph.
/// @param height The height of the lines.
/// @return The maximum area of water.
///
/// constraints
///
/// - 2 <= height.length <= 10^5
///
/// - 0 <= height[i] <= 10^4
///
/// @note https://leetcode.com/problems/container-with-most-water/
int maxArea(std::vector<int> &height);

/// @brief Find all unique triplets in the array which gives the sum of zero.
/// @param nums The array.
/// @return All unique triplets.
///
/// constraints
///
/// - 0 <= nums.length <= 3000
///
/// @note https://leetcode.com/problems/3sum/
std::vector<std::vector<int>> threeSum(std::vector<int> &nums);
}  // namespace twopointers

#endif  // TWOPOINTERS_H
