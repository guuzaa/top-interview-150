#include "graph/graph.h"

#include <array>
#include <queue>
#include <unordered_map>
#include <unordered_set>

namespace graph {
namespace {

void numIslandsDFS(std::vector<std::vector<char>> &grid, int row, int col) {
  int rows = static_cast<int>(grid.size());
  int cols = static_cast<int>(grid[0].size());
  if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == '0') {
    return;
  }
  grid[row][col] = '0';
  numIslandsDFS(grid, row - 1, col);
  numIslandsDFS(grid, row + 1, col);
  numIslandsDFS(grid, row, col - 1);
  numIslandsDFS(grid, row, col + 1);
}

}  // namespace

int numIslands(std::vector<std::vector<char>> &grid) {
  int islands = 0;
  int rows = static_cast<int>(grid.size());
  int cols = static_cast<int>(grid[0].size());
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      if (grid[row][col] == '0') {
        continue;
      }
      ++islands;
      numIslandsDFS(grid, row, col);
    }
  }
  return islands;
}

void solve(std::vector<std::vector<char>> &board) {
  int rows = static_cast<int>(board.size());
  int cols = static_cast<int>(board[0].size());
  std::queue<std::pair<int, int>> queue;
  for (int row = 0; row < rows; ++row) {
    for (auto col : {0, cols - 1}) {
      if (board[row][col] == 'O') {
        board[row][col] = '#';
        queue.push({row, col});
      }
    }
  }
  for (auto row : {0, rows - 1}) {
    for (int col = 0; col < cols; ++col) {
      if (board[row][col] == 'O') {
        board[row][col] = '#';
        queue.push({row, col});
      }
    }
  }
  constexpr std::array<std::pair<int, int>, 4> directions = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
  while (!queue.empty()) {
    auto &&[row, col] = queue.front();
    queue.pop();
    for (auto &&[dRow, dCol] : directions) {
      int newRow = row + dRow;
      int newCol = col + dCol;
      if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || board[newRow][newCol] != 'O') {
        continue;
      }
      board[newRow][newCol] = '#';
      queue.push({newRow, newCol});
    }
  }
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      if (board[row][col] == '#') {
        board[row][col] = 'O';
      } else if (board[row][col] == 'O') {
        board[row][col] = 'X';
      }
    }
  }
}

Node *cloneGraph(Node *node) {
  if (node == nullptr) {
    return nullptr;
  }
  std::unordered_map<int, Node *> visited;
  std::queue<Node *> queue;
  queue.push(node);
  Node *root = new Node(node->val);
  visited[root->val] = root;
  while (!queue.empty()) {
    auto current = queue.front();
    queue.pop();
    for (auto neighbor : current->neighbors) {
      if (visited.count(neighbor->val) == 0) {
        visited[neighbor->val] = new Node(neighbor->val);
        queue.push(neighbor);
      }
      visited[current->val]->neighbors.push_back(visited[neighbor->val]);
    }
  }
  return root;
}

std::vector<double> calcEquation(std::vector<std::vector<std::string>> &equations, std::vector<double> &values,
                                 std::vector<std::vector<std::string>> &queries) {
  std::unordered_map<std::string, std::unordered_map<std::string, double>> graph;
  for (size_t i = 0; i < equations.size(); ++i) {
    auto &&a = equations[i][0];
    auto &&b = equations[i][1];
    graph[a][b] = values[i];
    graph[b][a] = 1.0 / values[i];
  }
  std::vector<double> result;
  result.reserve(queries.size());
  for (auto &query : queries) {
    auto &a = query[0];
    auto &b = query[1];
    if (graph.count(a) == 0 || graph.count(b) == 0) {
      result.push_back(-1.0);
      continue;
    }
    std::queue<std::pair<std::string, double>> queue;
    queue.push({a, 1.0});
    std::unordered_set<std::string> visited = {a};
    while (!queue.empty()) {
      auto [current, value] = queue.front();
      queue.pop();
      if (current == b) {
        result.push_back(value);
        break;
      }
      for (auto &[neighbor, weight] : graph[current]) {
        if (visited.count(neighbor) == 0) {
          queue.push({neighbor, value * weight});
          visited.insert(neighbor);
        }
      }
    }
    if (visited.count(b) == 0) {
      result.push_back(-1.0);
    }
  }
  return result;
}

bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
  std::vector<int> in_degree(numCourses, 0);
  std::vector<std::vector<int>> graph(numCourses);
  for (auto &prerequisite : prerequisites) {
    ++in_degree[prerequisite[0]];
    graph[prerequisite[1]].push_back(prerequisite[0]);
  }
  std::queue<int> queue;
  for (int i = 0; i < numCourses; ++i) {
    if (in_degree[i] == 0) {
      queue.push(i);
    }
  }
  int count = 0;
  while (!queue.empty()) {
    auto current = queue.front();
    queue.pop();
    ++count;
    for (auto neighbor : graph[current]) {
      --in_degree[neighbor];
      if (in_degree[neighbor] == 0) {
        queue.push(neighbor);
      }
    }
  }
  return count == numCourses;
}

std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites) {
  std::vector<int> in_degree(numCourses, 0);
  std::vector<std::vector<int>> graph(numCourses);
  for (auto &prerequisite : prerequisites) {
    ++in_degree[prerequisite[0]];
    graph[prerequisite[1]].push_back(prerequisite[0]);
  }
  std::vector<int> result;
  result.reserve(numCourses);
  std::queue<int> queue;
  for (int i = 0; i < numCourses; ++i) {
    if (in_degree[i] == 0) {
      queue.push(i);
    }
  }
  while (!queue.empty()) {
    auto current = queue.front();
    queue.pop();
    result.push_back(current);
    for (auto neighbor : graph[current]) {
      --in_degree[neighbor];
      if (in_degree[neighbor] == 0) {
        queue.push(neighbor);
      }
    }
  }
  int n = static_cast<int>(result.size());
  return n == numCourses ? result : std::vector<int>();
}

int snakesAndLadders(std::vector<std::vector<int>> &board) {
  int n = static_cast<int>(board.size());
  int target = n * n;
  auto getCoordinates = [n](int position) -> std::pair<int, int> {
    position -= 1;
    int row = n - 1 - position / n;
    int col = (n - 1 - row) % 2 == 1 ? n - 1 - (position % n) : position % n;
    return {row, col};
  };

  std::queue<int> queue;
  queue.push(1);
  std::vector<int> distance(target + 1, -1);
  distance[1] = 0;
  while (!queue.empty()) {
    auto current = queue.front();
    queue.pop();
    for (int next = current + 1; next <= std::min(current + 6, target); ++next) {
      auto [row, col] = getCoordinates(next);
      int destination = board[row][col] == -1 ? next : board[row][col];
      if (distance[destination] == -1) {
        distance[destination] = distance[current] + 1;
        queue.push(destination);
      }
    }
  }

  return distance[target];
}

int minMutation(std::string startGene, std::string endGene, std::vector<std::string> &bank) {
  if (std::find(bank.begin(), bank.end(), endGene) == bank.end()) {
    return -1;
  }
  if (startGene == endGene) {
    return 0;
  }

  std::unordered_set<std::string> bankSet(bank.begin(), bank.end());
  std::queue<std::pair<std::string, int>> queue;
  queue.push({startGene, 0});
  std::unordered_set<std::string> visited = {startGene};
  while (!queue.empty()) {
    auto [current, steps] = queue.front();
    queue.pop();
    for (size_t i = 0; i < current.size(); ++i) {
      for (char c : {'A', 'C', 'G', 'T'}) {
        if (current[i] == c) {
          continue;
        }
        std::string next = current;
        next[i] = c;
        if (bankSet.count(next) == 0) {
          continue;
        }
        if (visited.count(next) == 0) {
          queue.push({next, steps + 1});
          visited.insert(next);
        }
        if (next == endGene) {
          return steps + 1;
        }
      }
    }
  }
  return -1;
}

int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList) {
  std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
  if (wordSet.count(endWord) == 0) {
    return 0;
  }
  std::queue<std::pair<std::string, int>> queue;
  queue.push({beginWord, 1});
  std::unordered_set<std::string> visited = {beginWord};
  while (!queue.empty()) {
    auto [current, steps] = queue.front();
    queue.pop();
    for (size_t i = 0; i < current.size(); ++i) {
      for (char c = 'a'; c <= 'z'; ++c) {
        if (current[i] == c) {
          continue;
        }
        std::string next = current;
        next[i] = c;
        if (wordSet.count(next) == 0 || visited.count(next) > 0) {
          continue;
        }
        queue.push({next, steps + 1});
        visited.insert(next);
        if (next == endWord) {
          return steps + 1;
        }
      }
    }
  }
  return 0;
}

}  // namespace graph
