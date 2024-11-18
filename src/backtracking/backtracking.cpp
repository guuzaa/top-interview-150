#include "backtracking/backtracking.h"

#include <unordered_map>

namespace backtracking {

namespace {
void letterCombinationsBacktracking(std::string_view digits, const std::vector<std::string_view> &digitToLetters,
                                    int index, std::string &combination, std::vector<std::string> &result) {
  if (combination.size() == digits.size()) {
    result.push_back(combination);
    return;
  }

  for (auto letter : digitToLetters.at(digits[index] - '2')) {
    combination.push_back(letter);
    letterCombinationsBacktracking(digits, digitToLetters, index + 1, combination, result);
    combination.pop_back();
  }
}

void combineBacktracking(int n, int start, std::vector<int> &combination, std::vector<std::vector<int>> &result) {
  if (combination.size() == combination.capacity()) {
    result.push_back(combination);
    return;
  }

  for (int i = start; i <= n; ++i) {
    combination.push_back(i);
    combineBacktracking(n, i + 1, combination, result);
    combination.pop_back();
  }
}

void permuteBacktracking(std::vector<int> &nums, int index, std::vector<int> &combination,
                         std::vector<std::vector<int>> &result) {
  if (combination.size() == combination.capacity()) {
    result.push_back(combination);
    return;
  }

  for (int i = index; i < static_cast<int>(nums.size()); ++i) {
    std::swap(nums[index], nums[i]);
    combination.push_back(nums[index]);
    permuteBacktracking(nums, index + 1, combination, result);
    std::swap(nums[index], nums[i]);
    combination.pop_back();
  }
}

void combinationSumBacktracking(std::vector<int> &candidates, int target, int index, std::vector<int> &combination,
                                std::vector<std::vector<int>> &result, int sum) {
  if (sum == target) {
    result.push_back(combination);
    return;
  }

  if (sum > target) {
    return;
  }

  for (int i = index; i < static_cast<int>(candidates.size()); ++i) {
    combination.push_back(candidates[i]);
    combinationSumBacktracking(candidates, target, i, combination, result, sum + candidates[i]);
    combination.pop_back();
  }
}

bool queueCannotAttack(int row, int col, const std::vector<int> &combination) {
  for (int i = 0; i < row; ++i) {
    if (combination[i] == col || std::abs(combination[i] - col) == std::abs(i - row)) {
      return false;
    }
  }
  return true;
}

void totalNQueensBacktracking(int n, int row, std::vector<int> &combination, int &cnt) {
  if (row == n) {
    ++cnt;
    return;
  }

  for (int col = 0; col < n; ++col) {
    if (!queueCannotAttack(row, col, combination)) {
      continue;
    }
    combination.push_back(col);
    totalNQueensBacktracking(n, row + 1, combination, cnt);
    combination.pop_back();
  }
}

void generateParenthesisBacktracking(int n, int left, int right, int index, std::string &combination,
                                     std::vector<std::string> &result) {
  if (index == 2 * n) {
    result.push_back(combination);
    return;
  }

  if (left < n) {
    combination.push_back('(');
    generateParenthesisBacktracking(n, left + 1, right, index + 1, combination, result);
    combination.pop_back();
  }

  if (right < left) {
    combination.push_back(')');
    generateParenthesisBacktracking(n, left, right + 1, index + 1, combination, result);
    combination.pop_back();
  }
}

bool existBacktracking(std::vector<std::vector<char>> &board, std::string word, int index, int row, int col) {
  if (index == static_cast<int>(word.size())) {
    return true;
  }

  if (row < 0 || row >= static_cast<int>(board.size()) || col < 0 || col >= static_cast<int>(board[0].size()) ||
      board[row][col] != word[index]) {
    return false;
  }

  board[row][col] = '#';
  bool result = existBacktracking(board, word, index + 1, row + 1, col) ||
                existBacktracking(board, word, index + 1, row - 1, col) ||
                existBacktracking(board, word, index + 1, row, col + 1) ||
                existBacktracking(board, word, index + 1, row, col - 1);
  board[row][col] = word[index];
  return result;
}

}  // namespace

std::vector<std::string> letterCombinations(std::string digits) {
  std::vector<std::string> result;
  if (digits.empty()) {
    return result;
  }

  std::string combination;
  combination.reserve(digits.size());
  const std::vector<std::string_view> digitToLetters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  letterCombinationsBacktracking(digits, digitToLetters, 0, combination, result);
  return result;
}

std::vector<std::vector<int>> combine(int n, int k) {
  std::vector<std::vector<int>> result;
  std::vector<int> combination;
  combination.reserve(k);
  combineBacktracking(n, 1, combination, result);
  return result;
}

std::vector<std::vector<int>> permute(std::vector<int> &nums) {
  std::vector<std::vector<int>> result;
  std::vector<int> combination;
  combination.reserve(nums.size());
  permuteBacktracking(nums, 0, combination, result);
  return result;
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
  std::vector<std::vector<int>> result;
  std::vector<int> combination;
  combinationSumBacktracking(candidates, target, 0, combination, result, 0);
  return result;
}

int totalNQueens(int n) {
  int cnt = 0;
  std::vector<int> combination;
  totalNQueensBacktracking(n, 0, combination, cnt);
  return cnt;
}

std::vector<std::string> generateParenthesis(int n) {
  std::vector<std::string> result;
  std::string combination;
  combination.reserve(2 * n);
  generateParenthesisBacktracking(n, 0, 0, 0, combination, result);
  return result;
}

bool exist(std::vector<std::vector<char>> &board, std::string word) {
  int m = board.size();
  int n = board[0].size();
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (board[i][j] == word[0] && existBacktracking(board, word, 0, i, j)) {
        return true;
      }
    }
  }
  return false;
}

}  // namespace backtracking
