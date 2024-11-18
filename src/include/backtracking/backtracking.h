#ifndef __BACKTRACKING_H__
#define __BACKTRACKING_H__

#include <string>
#include <vector>

namespace backtracking {
/// @brief Given a string containing digits from 2-9 inclusive, return all possible
/// letter combinations that the number could represent. Return the answer in any
/// order.
/// @param digits A string containing digits from 2-9 inclusive.
/// @return All possible letter combinations that the number could represent.
/// constraints:
///
/// - 0 <= digits.length <= 4
///
/// - 2 <= digits[i] <= 9
///
/// @note https://leetcode.com/problems/letter-combinations-of-a-phone-number/
std::vector<std::string> letterCombinations(std::string digits);

/// @brief Given two integers n and k, return all possible combinations of k numbers
/// chosen from the range [1, n].
/// @param n The range of numbers to choose from.
/// @param k The number of numbers to choose.
/// @return All possible combinations of k numbers chosen from the range [1, n].
/// constraints:
/// - 1 <= n <= 20
///
/// - 1 <= k <= n
///
/// @note https://leetcode.com/problems/combinations/
std::vector<std::vector<int>> combine(int n, int k);

/// @brief Given an array nums of distinct integers, return all the possible
/// permutations. You can return the answer in any order.
/// @param nums An array of distinct integers.
/// @return All the possible permutations.
/// constraints:
/// - 1 <= nums.length <= 6
///
/// - -10 <= nums[i] <= 10
///
/// @note https://leetcode.com/problems/permutations/
std::vector<std::vector<int>> permute(std::vector<int> &nums);

/// @brief Given a set of candidate numbers (candidates) and a target number (target),
/// find all unique combinations in candidates where the candidate numbers sum to
/// target.
/// @param candidates A set of candidate numbers.
/// @param target The target number.
/// @return All unique combinations in candidates where the candidate numbers sum to
/// target.
/// constraints:
/// - 1 <= candidates.length <= 30
///
/// - 1 <= candidates[i] <= 40
///
/// - All elements of candidates are distinct.
///
/// - 1 <= target <= 40
///
/// @note https://leetcode.com/problems/combination-sum/
std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target);

/// @brief The n-queens puzzle is the problem of placing n queens on an n x n chessboard
/// such that no two queens attack each other.
/// As for the rule, a queen can attack another queen if they are in the same row,
/// column, or diagonal.
/// @param n The size of the chessboard.
/// @return The number of distinct solutions to the n-queens puzzle.
/// constraints:
///
/// - 1 <= n <= 9
///
/// @note https://leetcode.com/problems/n-queens/
int totalNQueens(int n);

/// @brief Given n pairs of parentheses, write a function to generate all combinations
/// of well-formed parentheses.
/// @param n The number of pairs of parentheses.
/// @return All combinations of well-formed parentheses.
/// constraints:
///
/// - 1 <= n <= 8
///
/// @note https://leetcode.com/problems/generate-parentheses/
std::vector<std::string> generateParenthesis(int n);

/// @brief Given an m x n grid of characters board and a string word, return true if
/// word exists in the grid.
/// @param board The grid of characters.
/// @param word The string to search for.
/// @return True if the word exists in the grid, false otherwise.
/// constraints:
/// - m == board.length
///
/// - n == board[i].length
///
/// - 1 <= m, n <= 6
///
/// - 1 <= word.length <= 15
///
/// - board and word consists of only lowercase and uppercase English letters.
///
/// @note https://leetcode.com/problems/word-search/
bool exist(std::vector<std::vector<char>> &board, std::string word);
}  // namespace backtracking

#endif  // __BACKTRACKING_H__
