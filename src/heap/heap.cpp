#include "heap/heap.h"

#include <queue>

namespace heap {

int findKthLargest(std::vector<int> &nums, int k) {
  std::priority_queue<int> pq(nums.begin(), nums.end());
  for (int i = 0; i < k - 1; ++i) {
    pq.pop();
  }
  return pq.top();
}

std::vector<std::vector<int>> kSmallestPairs(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
  std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>,
                      std::greater<>>
      pq;
  int n = nums1.size();
  int m = nums2.size();
  for (int i = 0; i < std::min(n, k); ++i) {
    pq.push({nums1[i] + nums2[0], {i, 0}});
  }

  std::vector<std::vector<int>> result;
  result.reserve(k);
  while (k-- > 0 && !pq.empty()) {
    auto [sum, pair] = pq.top();
    auto [i, j] = pair;
    pq.pop();
    result.push_back({nums1[i], nums2[j]});
    if (j + 1 < m) {
      pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
    }
  }
  return result;
}

int findMaximizedCapital(int k, int w, std::vector<int> &profits, std::vector<int> &capital) {
  std::priority_queue<int> pq;
  std::vector<std::pair<int, int>> projects;
  int n = profits.size();
  projects.reserve(n);
  for (int i = 0; i < n; ++i) {
    projects.push_back({capital[i], profits[i]});
  }
  std::sort(projects.begin(), projects.end());
  int i = 0;
  while (k-- > 0) {
    while (i < n && projects[i].first <= w) {
      pq.push(projects[i].second);
      ++i;
    }
    if (pq.empty()) {
      break;
    }
    w += pq.top();
    pq.pop();
  }
  return w;
}

void MedianFinder::addNum(int num) {
  small_.push(num);
  large_.push(small_.top());
  small_.pop();
  if (small_.size() < large_.size()) {
    small_.push(large_.top());
    large_.pop();
  }
}

double MedianFinder::findMedian() const {
  auto s = small_.top();
  auto l = large_.top();
  if (small_.size() > large_.size()) {
    return s;
  } else if (small_.size() < large_.size()) {
    return l;
  }
  return (s + l) / 2.0;
}

}  // namespace heap
