#ifndef __TREE_H__
#define __TREE_H__

#include <vector>

namespace tree {

namespace quadtree {

class Node {
 public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;
  Node() : val(false), isLeaf(false), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}

  Node(bool _val, bool _isLeaf)
      : val(_val), isLeaf(_isLeaf), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
      : val(_val),
        isLeaf(_isLeaf),
        topLeft(_topLeft),
        topRight(_topRight),
        bottomLeft(_bottomLeft),
        bottomRight(_bottomRight) {}
};

/// @brief Construct a quad tree from a two-dimensional area using the following steps:
/// 1. Divide the area into four quadrants.
/// 2. If all four quadrants are the same, set the node as a leaf node.
/// 3. If the quadrants are not the same, set the node as a non-leaf node and recursively construct the quad tree for
/// each quadrant.
/// @param grid The two-dimensional area to construct the quad tree from.
/// @return The root node of the constructed quad tree.
/// constraints:
/// - n == grid.length == grid[i].length
///
/// - n == 2^x 0 <= x <= 6
///
/// @note https://leetcode.com/problems/construct-quad-tree/
Node *construct(std::vector<std::vector<int>> &grid);

}  // namespace quadtree

}  // namespace tree

#endif  // __TREE_H__
