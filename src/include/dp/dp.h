#ifndef __DP_H__
#define __DP_H__

#include <string>
#include <vector>

namespace dp {

/// @brief You are climbing a staircase. It takes n steps to reach the top.
///
/// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
///
/// constraints
///
/// - 1 <= n <= 45
///
/// @note https://leetcode.com/problems/climbing-stairs/
int climbStairs(int n);

/// @brief You are a professional robber planning to rob houses along a street.
/// Each house has a certain amount of money stashed, the only constraint stopping
/// you from robbing each of them is that adjacent houses have security systems
/// connected and it will automatically contact the police if two adjacent houses
/// were broken into on the same night.
///
/// Given an integer array nums representing the amount of money of each house,
/// return the maximum amount of money you can rob tonight without alerting the
/// police.
///
/// constraints
/// - 1 <= nums.length <= 100
///
/// - 0 <= nums[i] <= 400
///
/// @note https://leetcode.com/problems/house-robber/
int rob(std::vector<int> &nums);

/// @brief Given a string s and a dictionary of strings wordDict, return true if s
/// can be segmented into a space-separated sequence of one or more dictionary
/// words.
///
/// Note that the same word in the dictionary may be reused multiple times in the
/// segmentation.
///
/// constraints
/// - 1 <= s.length <= 300
///
/// - 1 <= wordDict.length <= 1000
///
/// - 1 <= wordDict[i].length <= 20
///
/// - s and wordDict[i] consist of only lowercase English letters.
///
/// - All the strings of wordDict are unique.
///
/// @note https://leetcode.com/problems/word-break/
bool wordBreak(std::string s, std::vector<std::string> &wordDict);

/// @brief You are given an integer array coins representing coins of different
/// denominations and an integer amount representing a total amount of money.
///
/// Return the fewest number of coins that you need to make up that amount. If
/// that amount of money cannot be made up by any combination of the coins,
/// return -1.
///
/// You may assume that you have an infinite number of each kind of coin.
///
/// constraints
/// - 1 <= coins.length <= 12
///
/// - 1 <= coins[i] <= 2^31 - 1
///
/// - 0 <= amount <= 10^4
///
/// @note https://leetcode.com/problems/coin-change/
int coinChange(std::vector<int> &coins, int amount);

/// @brief Given an integer array nums, return the length of the longest strictly
/// increasing subsequence.
///
/// constraints
/// - 1 <= nums.length <= 2500
///
/// - -10^4 <= nums[i] <= 10^4
///
/// @note https://leetcode.com/problems/longest-increasing-subsequence/
int lengthOfLIS(std::vector<int> &nums);
}  // namespace dp

#endif  // __DP_H__
