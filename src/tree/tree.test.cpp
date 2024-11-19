#include "tree/tree.h"

#include <gtest/gtest.h>

using namespace tree;

TEST(tree, construct) {
  std::vector<std::vector<int>> grid = {
      {{0, 1}, {1, 0}},
  };
  auto root = quadtree::construct(grid);
  EXPECT_EQ(root->val, false);
  EXPECT_EQ(root->isLeaf, false);
}
