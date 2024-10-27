#include "matrix/matrix.h"

#include <array>

namespace matrix {

bool isValidSudoku(std::vector<std::vector<char>> &board) {
  constexpr int n = 9;
  std::array<std::array<bool, n>, n> rowUsed = {};
  std::array<std::array<bool, n>, n> colUsed = {};
  std::array<std::array<bool, n>, n> boxUsed = {};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (board[i][j] == '.') {
        continue;
      }
      int num = static_cast<int>(board[i][j] - '1');
      int boxIndex = (i / 3) * 3 + j / 3;
      if (rowUsed[i][num] || colUsed[j][num] || boxUsed[boxIndex][num]) {
        return false;
      }
      rowUsed[i][num] = true;
      colUsed[j][num] = true;
      boxUsed[boxIndex][num] = true;
    }
  }
  return true;
}

std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
  std::vector<int> result;
  result.reserve(matrix.size() * matrix[0].size());

  int top = 0;
  int bottom = static_cast<int>(matrix.size()) - 1;
  int left = 0;
  int right = static_cast<int>(matrix[0].size()) - 1;

  while (true) {
    for (int i = left; i <= right; ++i) {
      result.push_back(matrix[top][i]);
    }
    ++top;
    if (top > bottom) {
      break;
    }

    for (int i = top; i <= bottom; ++i) {
      result.push_back(matrix[i][right]);
    }
    --right;
    if (left > right) {
      break;
    }

    for (int i = right; i >= left; --i) {
      result.push_back(matrix[bottom][i]);
    }
    --bottom;
    if (top > bottom) {
      break;
    }

    for (int i = bottom; i >= top; --i) {
      result.push_back(matrix[i][left]);
    }
    ++left;
    if (left > right) {
      break;
    }
  }

  return result;
}

void rotate(std::vector<std::vector<int>> &matrix) {
  int n = static_cast<int>(matrix.size());
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      std::swap(matrix[i][j], matrix[j][i]);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n / 2; ++j) {
      std::swap(matrix[i][j], matrix[i][n - 1 - j]);
    }
  }
}

void setZeros(std::vector<std::vector<int>> &matrix) {
  int m = static_cast<int>(matrix.size());
  int n = static_cast<int>(matrix[0].size());
  bool first_row_has_zero = std::any_of(matrix[0].begin(), matrix[0].end(), [](int x) { return x == 0; });
  bool first_col_has_zero =
      std::any_of(matrix.begin(), matrix.end(), [](const std::vector<int> &row) { return row[0] == 0; });

  // Use first row and column as markers
  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }

  // Set zeros based on markers (except first row and col)
  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
  }

  // Set first row to zeros if needed
  if (first_row_has_zero) {
    for (int j = 0; j < n; ++j) {
      matrix[0][j] = 0;
    }
  }

  // Set first column to zeros if needed
  if (first_col_has_zero) {
    for (int i = 0; i < m; ++i) {
      matrix[i][0] = 0;
    }
  }
}

void gameOfLife(std::vector<std::vector<int>> &board) {
  int m = static_cast<int>(board.size());
  int n = static_cast<int>(board[0].size());

  // Use 2 to mark cells that will become 1, and -1 to mark cells that will become 0
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int live_neighbors = 0;
      for (int x = -1; x <= 1; ++x) {
        for (int y = -1; y <= 1; ++y) {
          int r = i + x;
          int c = j + y;
          if (r >= 0 && r < m && c >= 0 && c < n && (board[r][c] == 1 || board[r][c] == -1)) {
            ++live_neighbors;
          }
        }
      }

      live_neighbors -= (board[i][j] == 1 || board[i][j] == -1) ? 1 : 0;
      if (board[i][j] == 1) {
        if (live_neighbors < 2 || live_neighbors > 3) {
          board[i][j] = -1;  // Will become 0
        }
      } else if (live_neighbors == 3) {
        board[i][j] = 2;  // Will become 1
      }
    }
  }

  // Update board with final states
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (board[i][j] == 2) {
        board[i][j] = 1;
      } else if (board[i][j] == -1) {
        board[i][j] = 0;
      }
    }
  }
}

}  // namespace matrix
