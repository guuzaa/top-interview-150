#include "binarytree/binarytree.h"

#include <gtest/gtest.h>
#include <queue>

namespace {
binarytree::TreeNode *arrayToTree(const std::vector<std::optional<int>> &nodes) {
  if (nodes.empty() || !nodes[0].has_value()) {
    return nullptr;
  }

  std::queue<binarytree::TreeNode *> q;
  binarytree::TreeNode *root = new binarytree::TreeNode(nodes[0].value());
  q.push(root);

  size_t i = 1;
  while (!q.empty() && i < nodes.size()) {
    binarytree::TreeNode *curr = q.front();
    q.pop();

    // Left child
    if (i < nodes.size() && nodes[i].has_value()) {
      curr->left = new binarytree::TreeNode(nodes[i].value());
      q.push(curr->left);
    }
    i++;

    // Right child
    if (i < nodes.size() && nodes[i].has_value()) {
      curr->right = new binarytree::TreeNode(nodes[i].value());
      q.push(curr->right);
    }
    i++;
  }

  return root;
}

void deleteTree(binarytree::TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

}  // namespace

TEST(binarytreeTest, maxDepth) {
  struct TestCase {
    std::vector<std::optional<int>> nodes;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {{3, 9, 20, std::nullopt, std::nullopt, 15, 7}, 3},
      {{1, std::nullopt, 2}, 2},
      {{}, 0},
  };

  for (const auto &test_case : test_cases) {
    binarytree::TreeNode *root = arrayToTree(test_case.nodes);
    EXPECT_EQ(binarytree::maxDepth(root), test_case.expected);
    deleteTree(root);
  }
}

TEST(binarytreeTest, isSameTree) {
  struct TestCase {
    std::vector<std::optional<int>> p;
    std::vector<std::optional<int>> q;
    bool expected;
  };
  std::vector<TestCase> test_cases = {
      {{1, 2, 3}, {1, 2, 3}, true},
      {{1, 2}, {1, std::nullopt, 2}, false},
      {{1, 2, 1}, {1, 1, 2}, false},
      {{10, 5, 15}, {10, 5, std::nullopt, std::nullopt, 15}, false},
  };

  for (const auto &test_case : test_cases) {
    binarytree::TreeNode *p = arrayToTree(test_case.p);
    binarytree::TreeNode *q = arrayToTree(test_case.q);
    EXPECT_EQ(binarytree::isSameTree(p, q), test_case.expected);
    deleteTree(p);
    deleteTree(q);
  }
}

TEST(binarytreeTest, invertTree) {
  struct TestCase {
    std::vector<std::optional<int>> nodes;
    std::vector<std::optional<int>> expected;
  };
  std::vector<TestCase> test_cases = {
      {{4, 2, 7, 1, 3, 6, 9}, {4, 7, 2, 9, 6, 3, 1}},
      {{2, 1, 3}, {2, 3, 1}},
      {{}, {}},
  };

  for (const auto &test_case : test_cases) {
    binarytree::TreeNode *root = arrayToTree(test_case.nodes);
    binarytree::TreeNode *expected = arrayToTree(test_case.expected);
    EXPECT_TRUE(isSameTree(binarytree::invertTree(root), expected));
    deleteTree(root);
    deleteTree(expected);
  }
}

TEST(binarytreeTest, isSymmetric) {
  struct TestCase {
    std::vector<std::optional<int>> nodes;
    bool expected;
  };
  std::vector<TestCase> test_cases = {
      // {{1, 2, 2, 3, 4, 4, 3}, true},
      // {{1, 2, 2, std::nullopt, 3, std::nullopt, 3}, false},
      // {{1, 2, 2, std::nullopt, 3, 3}, true},
      {{2, 3, 3, 4, 5, std::nullopt, 4}, false},
  };

  for (const auto &test_case : test_cases) {
    binarytree::TreeNode *root = arrayToTree(test_case.nodes);
    EXPECT_EQ(binarytree::isSymmetric(root), test_case.expected);
    deleteTree(root);
  }
}

TEST(binarytreeTest, buildTree) {
  struct TestCase {
    std::vector<int> preorder;
    std::vector<int> inorder;
    std::vector<std::optional<int>> expected;
  };
  std::vector<TestCase> test_cases = {
      {{3, 9, 20, 15, 7}, {9, 3, 15, 20, 7}, {3, 9, 20, std::nullopt, std::nullopt, 15, 7}},
      {{1, 2, 3}, {2, 1, 3}, {1, 2, 3}},
      {{1, 2}, {2, 1}, {1, 2}},
  };

  for (auto &&test_case : test_cases) {
    binarytree::TreeNode *root = binarytree::buildTree(test_case.preorder, test_case.inorder);
    binarytree::TreeNode *expected = arrayToTree(test_case.expected);
    EXPECT_TRUE(binarytree::isSameTree(root, expected));
    deleteTree(root);
    deleteTree(expected);
  }
}

TEST(binarytreeTest, buildTree2) {
  struct TestCase {
    std::vector<int> inorder;
    std::vector<int> postorder;
    std::vector<std::optional<int>> expected;
  };
  std::vector<TestCase> test_cases = {
      {{9, 3, 15, 20, 7}, {9, 15, 7, 20, 3}, {3, 9, 20, std::nullopt, std::nullopt, 15, 7}},
      {{2, 1, 3}, {2, 3, 1}, {1, 2, 3}},
      {{1, 2}, {2, 1}, {1, std::nullopt, 2}},
  };

  for (auto &&test_case : test_cases) {
    binarytree::TreeNode *root = binarytree::buildTree2(test_case.inorder, test_case.postorder);
    binarytree::TreeNode *expected = arrayToTree(test_case.expected);
    EXPECT_TRUE(binarytree::isSameTree(root, expected));
    deleteTree(root);
    deleteTree(expected);
  }
}

TEST(binarytreeTest, flatten) {
  struct TestCase {
    std::vector<std::optional<int>> nodes;
    std::vector<std::optional<int>> expected;
  };
  std::vector<TestCase> test_cases = {
      {{}, {}},
      {{1}, {1}},
      {{1, 2}, {1, std::nullopt, 2}},
      {{1, 2, 5, 3, 4, std::nullopt, 6},
       {1, std::nullopt, 2, std::nullopt, 3, std::nullopt, 4, std::nullopt, 5, std::nullopt, 6}},
  };

  for (auto &&test_case : test_cases) {
    binarytree::TreeNode *root = arrayToTree(test_case.nodes);
    binarytree::flatten(root);
    binarytree::TreeNode *expected = arrayToTree(test_case.expected);
    EXPECT_TRUE(binarytree::isSameTree(root, expected));
    deleteTree(root);
    deleteTree(expected);
  }
}

TEST(binarytreeTest, hasPathSum) {
  struct TestCase {
    std::vector<std::optional<int>> nodes;
    int targetSum;
    bool expected;
  };
  std::vector<TestCase> test_cases = {
      {{5, 4, 8, 11, std::nullopt, 13, 4, 7, 2, std::nullopt, std::nullopt, std::nullopt, 1}, 22, true},
      {{1, 2, 3}, 5, false},
      {{1, 2}, 0, false},
      {{1}, 1, true},
      {{}, 0, false},
  };

  for (auto &&test_case : test_cases) {
    binarytree::TreeNode *root = arrayToTree(test_case.nodes);
    EXPECT_EQ(binarytree::hasPathSum(root, test_case.targetSum), test_case.expected);
    deleteTree(root);
  }
}

TEST(binarytreeTest, sumNumbers) {
  struct TestCase {
    std::vector<std::optional<int>> nodes;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {{1, 2, 3}, 25},
      {{4, 9, 0, std::nullopt, 1}, 531},
      {{4, 9, 0, 5, 1}, 1026},
  };

  for (auto &&test_case : test_cases) {
    binarytree::TreeNode *root = arrayToTree(test_case.nodes);
    EXPECT_EQ(binarytree::sumNumbers(root), test_case.expected);
    deleteTree(root);
  }
}

TEST(binarytreeTest, maxPathSum) {
  struct TestCase {
    std::vector<std::optional<int>> nodes;
    int expected;
  };
  std::vector<TestCase> test_cases = {
      {{1, 2, 3}, 6},
      {{-10, 9, 20, std::nullopt, std::nullopt, 15, 7}, 42},
  };

  for (auto &&test_case : test_cases) {
    binarytree::TreeNode *root = arrayToTree(test_case.nodes);
    EXPECT_EQ(binarytree::maxPathSum(root), test_case.expected);
    deleteTree(root);
  }
}

TEST(binarytreeTest, countNodes) {
  struct TestCase {
    std::vector<std::optional<int>> nodes;
    int expected;
  };

  std::vector<TestCase> test_cases = {
      {{1, 2, 3, 4, 5, 6}, 6},
      {{}, 0},
      {{1}, 1},
  };
  for (auto &&test_case : test_cases) {
    binarytree::TreeNode *root = arrayToTree(test_case.nodes);
    EXPECT_EQ(binarytree::countNodes(root), test_case.expected);
    deleteTree(root);
  }
}

TEST(binarytreeTest, BSTIterator) {
  binarytree::TreeNode *root = arrayToTree({7, 3, 15, std::nullopt, std::nullopt, 9, 20});
  binarytree::BSTIterator iterator(root);
  EXPECT_EQ(iterator.next(), 3);
  EXPECT_EQ(iterator.next(), 7);
  EXPECT_TRUE(iterator.hasNext());
  EXPECT_EQ(iterator.next(), 9);
  EXPECT_EQ(iterator.next(), 15);
  EXPECT_EQ(iterator.next(), 20);
  EXPECT_FALSE(iterator.hasNext());
  deleteTree(root);
}

TEST(binarytreeTest, rightSideView) {
  struct TestCase {
    std::vector<std::optional<int>> nodes;
    std::vector<int> expected;
  };
  std::vector<TestCase> test_cases = {
      {{1, 2, 3, std::nullopt, 5, std::nullopt, 4}, {1, 3, 4}},
      {{1, std::nullopt, 3}, {1, 3}},
      {{}, {}},
  };
  for (auto &&test_case : test_cases) {
    binarytree::TreeNode *root = arrayToTree(test_case.nodes);
    EXPECT_EQ(binarytree::rightSideView(root), test_case.expected);
    deleteTree(root);
  }
}

TEST(binarytreeTest, averageOfLevels) {
  struct TestCase {
    std::vector<std::optional<int>> nodes;
    std::vector<double> expected;
  };
  std::vector<TestCase> test_cases = {
      {{3, 9, 20, 15, 7}, {3, 14.5, 11.0}},
      {{3, 9, 20, std::nullopt, std::nullopt, 15, 7}, {3, 14.5, 11.0}},
      {{1}, {1.0}},
  };
  for (auto &&test_case : test_cases) {
    binarytree::TreeNode *root = arrayToTree(test_case.nodes);
    EXPECT_EQ(binarytree::averageOfLevels(root), test_case.expected);
    deleteTree(root);
  }
}

TEST(binarytreeTest, levelOrder) {
  struct TestCase {
    std::vector<std::optional<int>> nodes;
    std::vector<std::vector<int>> expected;
  };
  std::vector<TestCase> test_cases = {
      {{3, 9, 20, 15, 7}, {{3}, {9, 20}, {15, 7}}},
      {{1}, {{1}}},
      {{}, {}},
  };
  for (auto &&test_case : test_cases) {
    binarytree::TreeNode *root = arrayToTree(test_case.nodes);
    EXPECT_EQ(binarytree::levelOrder(root), test_case.expected);
    deleteTree(root);
  }
}

TEST(binarytreeTest, zigzagLevelOrder) {
  struct TestCase {
    std::vector<std::optional<int>> nodes;
    std::vector<std::vector<int>> expected;
  };
  std::vector<TestCase> test_cases = {
      {{3, 9, 20, 15, 7}, {{3}, {20, 9}, {15, 7}}},
      {{1}, {{1}}},
      {{}, {}},
  };
  for (auto &&test_case : test_cases) {
    binarytree::TreeNode *root = arrayToTree(test_case.nodes);
    EXPECT_EQ(binarytree::zigzagLevelOrder(root), test_case.expected);
    deleteTree(root);
  }
}
