#include "binarytree/binarytree.h"
#include <algorithm>
#include <cmath>
#include <queue>

namespace binarytree {

namespace {
TreeNode *buildTreeByPreorderAndInorder(std::vector<int>::iterator preorderBegin,
                                        std::vector<int>::iterator preorderEnd, std::vector<int>::iterator inorderBegin,
                                        std::vector<int>::iterator inorderEnd) {
  if (preorderBegin == preorderEnd) {
    return nullptr;
  }
  auto root = new TreeNode(*preorderBegin);
  auto rootIndex = std::find(inorderBegin, inorderEnd, root->val) - inorderBegin;
  root->left = buildTreeByPreorderAndInorder(preorderBegin + 1, preorderBegin + rootIndex + 1, inorderBegin,
                                             inorderBegin + rootIndex);
  root->right = buildTreeByPreorderAndInorder(preorderBegin + rootIndex + 1, preorderEnd, inorderBegin + rootIndex + 1,
                                              inorderEnd);
  return root;
}

TreeNode *buildTreeByInorderAndPostorder(std::vector<int>::iterator inorderBegin, std::vector<int>::iterator inorderEnd,
                                         std::vector<int>::iterator postorderBegin,
                                         std::vector<int>::iterator postorderEnd) {
  if (inorderBegin == inorderEnd) {
    return nullptr;
  }
  auto root = new TreeNode(*(postorderEnd - 1));
  auto rootIndex = std::find(inorderBegin, inorderEnd, root->val) - inorderBegin;
  root->left = buildTreeByInorderAndPostorder(inorderBegin, inorderBegin + rootIndex, postorderBegin,
                                              postorderBegin + rootIndex);
  root->right = buildTreeByInorderAndPostorder(inorderBegin + rootIndex + 1, inorderEnd, postorderBegin + rootIndex,
                                               postorderEnd - 1);
  return root;
}

int sumNumbersHelper(TreeNode *root, int currentSum) {
  if (root == nullptr) {
    return 0;
  }
  currentSum = currentSum * 10 + root->val;
  if (root->left == nullptr && root->right == nullptr) {
    return currentSum;
  }
  return sumNumbersHelper(root->left, currentSum) + sumNumbersHelper(root->right, currentSum);
}

int maxPathSumHelper(TreeNode *root, int &maxSum) {
  if (root == nullptr) {
    return 0;
  }
  int leftGain = std::max(maxPathSumHelper(root->left, maxSum), 0);
  int rightGain = std::max(maxPathSumHelper(root->right, maxSum), 0);
  maxSum = std::max(maxSum, root->val + leftGain + rightGain);
  return root->val + std::max(leftGain, rightGain);
}

}  // namespace

int maxDepth(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  constexpr int depth = 1;
  return depth + std::max(maxDepth(root->left), maxDepth(root->right));
}

bool isSameTree(TreeNode *p, TreeNode *q) {
  if (p == nullptr && q == nullptr) {
    return true;
  }
  if (p == nullptr || q == nullptr) {
    return false;
  }
  return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

TreeNode *invertTree(TreeNode *root) {
  if (root == nullptr) {
    return root;
  }
  std::swap(root->left, root->right);
  invertTree(root->left);
  invertTree(root->right);
  return root;
}

bool isSymmetric(TreeNode *root) {
  std::queue<TreeNode *> queue;
  queue.emplace(root->left);
  queue.emplace(root->right);
  while (!queue.empty()) {
    auto first = queue.front();
    queue.pop();
    auto second = queue.front();
    queue.pop();

    if (first == nullptr && second == nullptr) {
      continue;
    }
    if (first == nullptr || second == nullptr) {
      return false;
    }
    if (first->val != second->val) {
      return false;
    }
    queue.emplace(first->left);
    queue.emplace(second->right);
    queue.emplace(first->right);
    queue.emplace(second->left);
  }
  return true;
}

TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
  if (preorder.empty() || inorder.empty()) {
    return nullptr;
  }
  return buildTreeByPreorderAndInorder(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}

TreeNode *buildTree2(std::vector<int> &inorder, std::vector<int> &postorder) {
  if (inorder.empty() || postorder.empty()) {
    return nullptr;
  }
  return buildTreeByInorderAndPostorder(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
}

Node *connect(Node *root) {
  if (root == nullptr) {
    return root;
  }
  std::queue<Node *> queue;
  queue.emplace(root);
  while (!queue.empty()) {
    int levelSize = static_cast<int>(queue.size());
    for (int i = 0; i < levelSize; ++i) {
      auto node = queue.front();
      queue.pop();
      if (i < levelSize - 1) {
        node->next = queue.front();
      }
      if (node->left != nullptr) {
        queue.emplace(node->left);
      }
      if (node->right != nullptr) {
        queue.emplace(node->right);
      }
    }
  }
  return root;
}

void flatten(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  flatten(root->left);
  flatten(root->right);

  auto right = root->right;
  root->right = root->left;
  root->left = nullptr;
  while (root->right != nullptr) {
    root = root->right;
  }
  root->right = right;
}

bool hasPathSum(TreeNode *root, int targetSum) {
  if (root == nullptr) {
    return false;
  }
  int headVal = root->val;
  if (root->left == nullptr && root->right == nullptr) {
    return headVal == targetSum;
  }
  return hasPathSum(root->left, targetSum - headVal) || hasPathSum(root->right, targetSum - headVal);
}

int sumNumbers(TreeNode *root) { return sumNumbersHelper(root, 0); }

int maxPathSum(TreeNode *root) {
  int maxSum = root->val;
  maxPathSumHelper(root, maxSum);
  return maxSum;
}

int countNodes(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  return 1 + countNodes(root->left) + countNodes(root->right);
}

BSTIterator::BSTIterator(TreeNode *root) {
  while (root != nullptr) {
    stack_.emplace(root);
    root = root->left;
  }
}

int BSTIterator::next() {
  auto node = stack_.top();
  stack_.pop();
  auto result = node->val;
  node = node->right;
  while (node != nullptr) {
    stack_.emplace(node);
    node = node->left;
  }
  return result;
}

bool BSTIterator::hasNext() { return !stack_.empty(); }

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (root == nullptr || p == root || q == root) {
    return root;
  }
  auto left = lowestCommonAncestor(root->left, p, q);
  auto right = lowestCommonAncestor(root->right, p, q);
  // p and q are in different subtrees
  if (left != nullptr && right != nullptr) {
    return root;
  }
  return left != nullptr ? left : right;
}

}  // namespace binarytree
