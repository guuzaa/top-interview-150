#ifndef __MATRIX_MATRIX_H__
#define __MATRIX_MATRIX_H__

#include <vector>

namespace matrix {
/// @brief Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the
/// following rules:
/// - Each row must contain the digits 1-9 without repetition.
/// - Each column must contain the digits 1-9 without repetition.
/// - Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
/// @param board The 9 x 9 Sudoku board.
/// @return True if the board is valid, false otherwise.
///
/// constraints:
///
/// - board.size() == 9
///
/// - board[i].size() == 9
///
/// - board[i][j] is a digit or '.'
///
/// @note https://leetcode.com/problems/valid-sudoku/
bool isValidSudoku(std::vector<std::vector<char>> &board);

/// @brief Given an m x n matrix, return all elements of the matrix in spiral order.
/// @param matrix The m x n matrix.
/// @return All elements of the matrix in spiral order.
///
/// constraints:
///
/// - m == matrix.size()
///
/// - n == matrix[i].size()
///
/// - 1 <= m, n <= 10
///
/// @note https://leetcode.com/problems/spiral-matrix/
std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix);

/// @brief You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
/// @param matrix The n x n 2D matrix representing an image.
///
/// constraints:
///
/// - n == matrix.size()
///
/// - 1 <= n <= 20
///
/// - -1000 <= matrix[i][j] <= 1000
///
/// @note https://leetcode.com/problems/rotate-image/
void rotate(std::vector<std::vector<int>> &matrix);

/// @brief Given an m x n integer matrix, if an element is 0, set its entire row and column to 0's.
/// @param matrix The m x n integer matrix.
///
/// constraints:
///
/// - m == matrix.size()
///
/// - n == matrix[i].size()
///
/// - 1 <= m, n <= 20
///
/// @note https://leetcode.com/problems/set-matrix-zeroes/
void setZeros(std::vector<std::vector<int>> &matrix);

/// @brief You are given an n x n 2D matrix representing the state of the game "Game of Life".
/// @param board The n x n 2D matrix representing the state of the game "Game of Life".
/// The board needs to be updated simultaneously.
///
/// constraints:
///
/// - n == board.size()
///
/// - n == board[i].size()
///
/// - 1 <= n <= 25
///
/// @note https://leetcode.com/problems/game-of-life/
void gameOfLife(std::vector<std::vector<int>> &board);

}  // namespace matrix

#endif  // __MATRIX_MATRIX_H__
