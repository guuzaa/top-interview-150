#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <stack>
#include <vector>

namespace binarytree {

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/// @brief Given the root of a binary tree, return its maximum depth.
/// @param root a binary tree
/// @return the maximum depth of the binary tree
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [0, 10^4].
///
/// - -100 <= Node.val <= 100
///
/// @note https://leetcode.com/problems/maximum-depth-of-binary-tree/
int maxDepth(TreeNode *root);

/// @brief Given the roots of two binary trees p and q, write a function to check if they are the same or not.
/// @param p a binary tree
/// @param q another binary tree
/// @return true if p and q are the same, false otherwise
///
/// constraints:
///
/// - The number of nodes in both trees is in the range [0, 100].
///
/// - -100 <= Node.val <= 100
///
/// @note https://leetcode.com/problems/same-tree/
bool isSameTree(TreeNode *p, TreeNode *q);

/// @brief Given the root of a binary tree, invert the tree and return its root.
/// @param root a binary tree
/// @return the root of the inverted binary tree
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [0, 100].
///
/// - -100 <= Node.val <= 100
///
/// @note https://leetcode.com/problems/invert-binary-tree/
TreeNode *invertTree(TreeNode *root);

/// @brief Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
/// @param root a binary tree
/// @return true if the binary tree is symmetric, false otherwise
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [1, 1000].
///
/// @note https://leetcode.com/problems/symmetric-tree/
bool isSymmetric(TreeNode *root);

/// @brief Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and
/// inorder is the inorder traversal of the same tree, construct and return the binary tree.
/// @param preorder the preorder traversal of a binary tree
/// @param inorder the inorder traversal of a binary tree
/// @return the root of the binary tree
///
/// constraints:
///
/// - 1 <= preorder.length <= 3000
///
/// - inorder.length == preorder.length
///
/// - -3000 <= Node.val <= 3000
///
/// - All the values of preorder and inorder are unique.
///
/// @note https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder);

/// @brief Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and
/// postorder is the postorder traversal of the same tree, construct and return the binary tree.
/// @param inorder the inorder traversal of a binary tree
/// @param postorder the postorder traversal of a binary tree
/// @return the root of the binary tree
///
/// constraints:
///
/// - 1 <= inorder.length <= 3000
///
/// - postorder.length == inorder.length
///
/// - -3000 <= Node.val <= 3000
///
/// - All the values of inorder and postorder are unique.
///
/// @note https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
TreeNode *buildTree2(std::vector<int> &inorder, std::vector<int> &postorder);

struct Node {
 public:
  int val;
  Node *left;
  Node *right;
  Node *next;
  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int x, Node *left, Node *right, Node *next) : val(x), left(left), right(right), next(next) {}
};

/// @brief You are given a perfect binary tree where all leaves are on the same level, and every parent has two
/// children. The binary tree has the following definition:
/// @param root a perfect binary tree
/// @return the root of the binary tree
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [0, 6000].
///
/// - -100 <= Node.val <= 100
///
/// @note https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
Node *connect(Node *root);

/// @brief Given the root of a binary tree, flatten the tree into a "linked list":
/// @param root a binary tree
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [0, 2000].
///
/// - -100 <= Node.val <= 100
///
/// @note https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
void flatten(TreeNode *root);

/// @brief Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path
/// such that adding up all the values along the path equals targetSum.
/// @param root a binary tree
/// @param targetSum an integer
/// @return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum,
/// false otherwise
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [0, 5000].
///
/// - -1000 <= Node.val <= 1000
///
/// - -1000 <= targetSum <= 1000
///
/// @note https://leetcode.com/problems/path-sum/
bool hasPathSum(TreeNode *root, int targetSum);

/// @brief You are given the root of a binary tree containing digits from 0 to 9 only.
/// @param root a binary tree
/// @return the total sum of all root-to-leaf numbers
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [1, 1000].
///
/// - 0 <= Node.val <= 9
///
/// - The depth of the tree will not exceed 10.
///
/// @note https://leetcode.com/problems/sum-root-to-leaf-numbers/
int sumNumbers(TreeNode *root);

/// @brief A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge
/// connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass
/// through the root.
/// @param root a binary tree
/// @return the maximum path sum
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [1, 3 * 10^4].
///
/// - -1000 <= Node.val <= 1000
///
/// @note https://leetcode.com/problems/binary-tree-maximum-path-sum/
int maxPathSum(TreeNode *root);

/// @brief Given the root of a complete binary tree, return the number of the nodes in the tree.
/// @param root a complete binary tree
/// @return the number of the nodes in the tree
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [0, 5 * 10^4].
///
/// - 0 <= Node.val <= 5 * 10^4
///
/// - The tree is guaranteed to be a complete binary tree.
///
/// @note https://leetcode.com/problems/count-complete-tree-nodes/
int countNodes(TreeNode *root);

/// @brief Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search
/// tree (BST).
/// constraints:
///
/// - The number of nodes in the tree is in the range [1, 10^5].
///
/// - 0 <= Node.val <= 10^6
///
/// - At most 10^5 calls will be made to hasNext, and next.
///
/// @note https://leetcode.com/problems/binary-search-tree-iterator/
class BSTIterator {
 public:
  BSTIterator(TreeNode *root);
  int next();
  bool hasNext();

 private:
  std::stack<TreeNode *> stack_;
};

/// @brief Given a binary tree, find the lowest common ancestor (LCA) node of two given nodes in the binary tree.
/// @param root a binary tree
/// @param p a node in the binary tree
/// @param q another node in the binary tree
/// @return the lowest common ancestor of p and q
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [2, 10^5].
///
/// - -10^9 <= Node.val <= 10^9
///
/// - All Node.val are unique.
///
/// - p != q
///
/// - p and q will exist in the binary tree.
///
/// @note https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);

/// @brief Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the
/// nodes you can see ordered from top to bottom.
/// @param root a binary tree
/// @return the values of the nodes you can see ordered from top to bottom
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [0, 100].
///
/// - -100 <= Node.val <= 100
///
/// @note https://leetcode.com/problems/binary-tree-right-side-view/
std::vector<int> rightSideView(TreeNode *root);

/// @brief Given the root of a binary tree, return the average value of the nodes on each level.
/// @param root a binary tree
/// @return the average value of the nodes on each level
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [1, 10^4].
///
/// - 0 <= Node.val <= 10^5
///
/// @note https://leetcode.com/problems/average-of-levels-in-binary-tree/
std::vector<double> averageOfLevels(TreeNode *root);

/// @brief Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to
/// right, level by level).
/// @param root a binary tree
/// @return the level order traversal of its nodes' values
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [0, 2000].
///
/// - -1000 <= Node.val <= 1000
///
/// @note https://leetcode.com/problems/binary-tree-level-order-traversal/
std::vector<std::vector<int>> levelOrder(TreeNode *root);

/// @brief Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from
/// left to right, then right to left for the next level and alternate between).
/// @param root a binary tree
/// @return the zigzag level order traversal of its nodes' values
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [0, 2000].
///
/// - -100 <= Node.val <= 100
///
/// @note https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root);

/// @brief Given the root of a binary tree, return the inorder traversal of its nodes' values.
/// @param root a binary tree
/// @return the inorder traversal of its nodes' values
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [0, 100].
///
/// - -100 <= Node.val <= 100
///
/// @note https://leetcode.com/problems/binary-tree-inorder-traversal/
std::vector<int> inorderTraversal(TreeNode *root);

/// @brief Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of
/// any two nodes.
/// @param root a binary search tree
/// @return the minimum absolute difference between the values of any two nodes
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [2, 10^4].
///
/// - 0 <= Node.val <= 10^5
///
/// @note https://leetcode.com/problems/minimum-absolute-difference-in-bst/
int getMinimumDifference(TreeNode *root);

/// @brief Given the root of a binary search tree, and an integer k, return the k-th smallest value (1-indexed) of all
/// the values of the nodes in the tree.
/// @param root a binary search tree
/// @param k an integer
/// @return the k-th smallest value (1-indexed) of all the values of the nodes in the tree
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [1, 10^4].
///
/// - 1 <= k <= 10^4
///
/// @note https://leetcode.com/problems/kth-smallest-element-in-a-bst/
int kthSmallest(TreeNode *root, int k);

/// @brief Given the root of a binary tree, determine if it is a valid binary search tree (BST).
/// @param root a binary tree
/// @return true if the binary tree is a valid binary search tree, false otherwise
///
/// constraints:
///
/// - The number of nodes in the tree is in the range [1, 10^4].
///
/// - -2^31 <= Node.val <= 2^31 - 1
///
/// @note https://leetcode.com/problems/validate-binary-search-tree/
bool isValidBST(TreeNode *root);

/// @brief Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced
/// binary search tree.
/// @param nums an integer array
/// @return the root of the height-balanced binary search tree
///
/// constraints:
///
/// - 1 <= nums.length <= 10^4
///
/// - -10^4 <= nums[i] <= 10^4
///
/// - nums is sorted in a strictly increasing order.
///
/// @note https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
TreeNode *sortedArrayToBST(std::vector<int> &nums);

}  // namespace binarytree
#endif  // __BINARYTREE_H__
