#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <string>
#include <vector>

namespace graph {

/// @brief Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
/// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
/// You may assume all four edges of the grid are all surrounded by water.
/// @param grid 2d grid map of '1's (land) and '0's (water)
/// @return number of islands
/// constraints:
///
/// - m == grid.length
///
/// - n == grid[i].length
///
/// - 1 <= m, n <= 300
///
/// @note https://leetcode.com/problems/number-of-islands/
int numIslands(std::vector<std::vector<char>> &grid);

/// @brief Given a 2d board containing 'X' and 'O', capture all regions surrounded by 'X'.
/// A region is captured by flipping all 'O's into 'X's in that surrounded region.
/// @param board 2d board containing 'X' and 'O'
/// constraints:
///
/// - m == board.length
///
/// - n == board[i].length
///
/// - 1 <= m, n <= 200
///
/// - board[i][j] is 'X' or 'O'
///
/// @note https://leetcode.com/problems/surrounded-regions/
void solve(std::vector<std::vector<char>> &board);

class Node {
 public:
  int val;
  std::vector<Node *> neighbors;
  Node() : val(0), neighbors(std::vector<Node *>()) {}
  Node(int _val) : val(_val), neighbors(std::vector<Node *>()) {}
  Node(int _val, std::vector<Node *> _neighbors) : val(_val), neighbors(_neighbors) {}
};

/// @brief Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph.
/// @param node reference of a node in a connected undirected graph
/// @return deep copy (clone) of the graph
/// constraints:
///
/// - The number of nodes in the graph is in the range [0, 100].
///
/// - 1 <= Node.val <= 100
///
/// - Node.val is unique for each node.
///
/// - There are no repeated edges and no self-loops in the graph.
///
/// - The Graph is connected and all nodes can be visited starting from the given node.
///
/// @note https://leetcode.com/problems/clone-graph/
Node *cloneGraph(Node *node);

/// @brief You are given an array of variable equations and an array of values. You are also given some queries,
/// and you need to return the answers for each query.
/// @param equations a list of variable equations
/// @param values a list of values
/// @param queries a list of queries
/// @return a list of double results
/// constraints:
///
/// - 1 <= equations.length <= 20
///
/// - equations[i].length == 2
///
/// - 1 <= equations[i][0].length, equations[i][1].length <= 5
///
/// - values[i] > 0
///
/// @note https://leetcode.com/problems/evaluate-division/
std::vector<double> calcEquation(std::vector<std::vector<std::string>> &equations, std::vector<double> &values,
                                 std::vector<std::vector<std::string>> &queries);

/// @brief There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
/// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first
/// if you want to take course ai.
/// @param numCourses number of courses
/// @param prerequisites prerequisites
/// @return true if you can finish all courses, false otherwise
/// constraints:
///
/// - 1 <= numCourses <= 2000
///
/// - 0 <= prerequisites.length <= 5000
///
/// - prerequisites[i].length == 2
///
/// - 0 <= ai, bi < numCourses
///
/// - All the pairs [ai, bi] are unique.
///
/// @note https://leetcode.com/problems/course-schedule/
bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites);

/// @brief There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
/// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first
/// if you want to take course ai.
/// @param numCourses number of courses
/// @param prerequisites prerequisites
/// @return a list of int results
/// constraints:
///
/// - 1 <= numCourses <= 2000
///
/// - 0 <= prerequisites.length <= numCourses * (numCourses - 1)
///
/// - prerequisites[i].length == 2
///
/// - 0 <= ai, bi < numCourses
///
/// - ai != bi
///
/// - All the pairs [ai, bi] are distinct.
///
/// @note https://leetcode.com/problems/course-schedule-ii/
std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites);

}  // namespace graph

#endif  // __GRAPH_H__
