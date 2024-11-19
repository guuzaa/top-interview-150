#include "tree/tree.h"

namespace tree {

namespace quadtree {

namespace {

bool isSame(std::vector<std::vector<int>> &grid, int x, int y, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[x + i][y + j] != grid[x][y]) {
        return false;
      }
    }
  }
  return true;
}

void constructHelper(Node *root, std::vector<std::vector<int>> &grid, int x, int y, int n) {
  if (isSame(grid, x, y, n)) {
    root->isLeaf = true;
    root->val = grid[x][y];
    return;
  }

  int half = n / 2;
  root->topLeft = new Node();
  constructHelper(root->topLeft, grid, x, y, half);
  root->topRight = new Node();
  constructHelper(root->topRight, grid, x, y + half, half);
  root->bottomLeft = new Node();
  constructHelper(root->bottomLeft, grid, x + half, y, half);
  root->bottomRight = new Node();
  constructHelper(root->bottomRight, grid, x + half, y + half, half);
}

}  // namespace

Node *construct(std::vector<std::vector<int>> &grid) {
  int n = grid.size();
  auto *root = new Node();
  constructHelper(root, grid, 0, 0, n);
  return root;
}

}  // namespace quadtree

}  // namespace tree
