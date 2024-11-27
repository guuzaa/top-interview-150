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
///
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
///
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
///
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
///
/// - 1 <= nums.length <= 2500
///
/// - -10^4 <= nums[i] <= 10^4
///
/// @note https://leetcode.com/problems/longest-increasing-subsequence/
int lengthOfLIS(std::vector<int> &nums);

/// @brief Given a triangle array, return the minimum path sum from top to bottom.
///
/// For each step, you may move to an adjacent number of the row below. More
/// formally, if you are on index i on the current row, you may move to either
/// index i or index i + 1 on the next row.
///
/// constraints
///
/// - 1 <= triangle.length <= 200
///
/// - triangle[i].length == triangle[i - 1].length + 1
///
/// - -10^4 <= triangle[i][j] <= 10^4
///
/// @note https://leetcode.com/problems/triangle/
int minimumTotal(std::vector<std::vector<int>> &triangle);

/// @brief Given a m x n grid filled with non-negative numbers, find a path from
/// top left to bottom right, which minimizes the sum of all numbers along its
/// path.
///
/// constraints
///
/// - m == grid.length
///
/// - n == grid[i].length
///
/// - 1 <= m, n <= 200
///
/// - 0 <= grid[i][j] <= 200
///
/// @note https://leetcode.com/problems/minimum-path-sum/
int minPathSum(std::vector<std::vector<int>> &grid);

/// @brief A robot is located at the top-left corner of a m x n grid.
///
/// The robot can only move either down or right at any point in time. The robot
/// is trying to reach the bottom-right corner of the grid.
///
/// constraints
///
/// - m == obstacleGrid.length
///
/// - n == obstacleGrid[i].length
///
/// - 1 <= m, n <= 100
///
/// - obstacleGrid[i][j] is 0 or 1.
///
/// @note https://leetcode.com/problems/unique-paths-ii/
int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid);

/// @brief Given a string s, return the longest palindromic substring in s.
///
/// constraints
/// - 1 <= s.length <= 1000
///
/// - s consist of only digits and English letters.
///
/// @note https://leetcode.com/problems/longest-palindromic-substring/
std::string longestPalindrome(std::string s);

/// @brief Given strings s1, s2, and s3, find whether s3 is formed by an
/// interleaving of s1 and s2.
///
/// constraints
///
/// - 1 <= s1.length, s2.length <= 100
///
/// - 0 <= s3.length <= 200
///
/// - s1, s2, and s3 consist of only lowercase English letters.
///
/// @note https://leetcode.com/problems/interleaving-string/
bool isInterleave(std::string s1, std::string s2, std::string s3);

/// @brief Given two strings word1 and word2, return the minimum number of
/// operations required to convert word1 to word2.
///
/// You have the following three operations permitted on a word:
/// - Insert a character
/// - Delete a character
/// - Replace a character
///
/// constraints
///
/// - 0 <= word1.length, word2.length <= 500
///
/// - word1 and word2 consist of only lowercase English letters.
///
/// @note https://leetcode.com/problems/edit-distance/
int minDistance(std::string word1, std::string word2);

/// @brief You are given an array prices where prices[i] is the price of a given
/// stock on the ith day.
///
/// Find the maximum profit you can achieve. You may complete at most two
/// transactions.
///
/// You must sell the stock before you buy again.
///
/// constraints
///
/// - 1 <= prices.length <= 10^5
///
/// - 0 <= prices[i] <= 10^5
///
/// @note https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
int maxProfit3(std::vector<int> &prices);

/// @brief You are given an array prices where prices[i] is the price of a given
/// stock on the ith day.
///
/// Find the maximum profit you can achieve. You may complete at most k
/// transactions.
///
/// constraints
///
/// - 1 <= k <= 100
///
/// - 1 <= prices.length <= 1000
///
/// - 0 <= prices[i] <= 1000
///
/// @note https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
int maxProfit4(int k, std::vector<int> &prices);

/// @brief Given a 2D binary matrix filled with 0's and 1's, find the largest
/// square containing only 1's and return its area.
///
/// constraints
///
/// - m == matrix.length
///
/// - n == matrix[i].length
///
/// - 1 <= m, n <= 300
///
/// @note https://leetcode.com/problems/maximal-square/
int maximalSquare(std::vector<std::vector<char>> &matrix);
}  // namespace dp

#endif  // __DP_H__
