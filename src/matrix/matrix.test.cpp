#include "matrix/matrix.h"

#include <gtest/gtest.h>

TEST(MatrixTest, isValidSudoku) {
  struct TestCase {
    std::vector<std::vector<char>> board;
    bool expected;
  };

  std::vector<TestCase> test_cases = {{{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}},
                                       true},
                                      {
                                          {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                                           {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                           {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                           {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                           {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                           {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                           {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                           {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                           {'.', '.', '.', '.', '8', '.', '.', '7', '9'}},
                                          false  // Invalid because 8 appears twice in first column
                                      },
                                      {
                                          {{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                           {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                           {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                           {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                           {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                           {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                           {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                           {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                           {'.', '.', '.', '.', '.', '.', '.', '.', '.'}},
                                          true  // Empty board is valid
                                      }};

  for (auto &&tc : test_cases) {
    EXPECT_EQ(matrix::isValidSudoku(tc.board), tc.expected);
  }
}

TEST(MatrixTest, spiralOrder) {
  struct TestCase {
    std::vector<std::vector<int>> matrix;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases = {
      {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {1, 2, 3, 6, 9, 8, 7, 4, 5}},
      {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}, {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}},
      {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}}, {1, 2, 3, 6, 9, 12, 11, 10, 7, 4, 5, 8}},
      {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}},
       {1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10}},
  };

  for (auto &&tc : test_cases) {
    EXPECT_EQ(matrix::spiralOrder(tc.matrix), tc.expected);
  }
}

TEST(MatrixTest, rotate) {
  struct TestCase {
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> expected;
  };
  std::vector<TestCase> test_cases = {
      {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}},
      {{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}},
       {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}}},
      {{{1}}, {{1}}},
      {{{1, 2}, {3, 4}}, {{3, 1}, {4, 2}}},
  };
  for (auto &&tc : test_cases) {
    matrix::rotate(tc.matrix);
    EXPECT_EQ(tc.matrix, tc.expected);
  }
}

TEST(MatrixTest, setZeros) {
  struct TestCase {
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> expected;
  };
  std::vector<TestCase> test_cases = {
      {{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}},
      {{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}}, {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}}},
      {{{1, 0, 3}}, {{0, 0, 0}}},
      {{{1}, {0}}, {{0}, {0}}},
      {{{0}, {1}}, {{0}, {0}}},
  };
  for (auto &&tc : test_cases) {
    matrix::setZeros(tc.matrix);
    EXPECT_EQ(tc.matrix, tc.expected);
  }
}

TEST(MatrixTest, gameOfLife) {
  struct TestCase {
    std::vector<std::vector<int>> board;
    std::vector<std::vector<int>> expected;
  };
  std::vector<TestCase> test_cases = {
      {{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}}, {{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}}},
      {{{1, 1}, {1, 0}}, {{1, 1}, {1, 1}}},
      {{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}},
      {{{1}}, {{0}}},
  };
  for (auto &&tc : test_cases) {
    matrix::gameOfLife(tc.board);
    EXPECT_EQ(tc.board, tc.expected);
  }
}
