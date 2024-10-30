#include "intervals/intervals.h"

#include <algorithm>

namespace intervals {

std::vector<std::string> summaryRanges(std::vector<int> &nums) {
  int n = static_cast<int>(nums.size());
  int i = 0;
  int j = 0;
  std::vector<std::string> ans;
  while (j < n) {
    while (j + 1 < n && nums[j + 1] == nums[j] + 1) {
      ++j;
    }
    if (i == j) {
      ans.push_back(std::to_string(nums[i]));
    } else {
      ans.push_back(std::to_string(nums[i]) + "->" + std::to_string(nums[j]));
    }
    i = ++j;
  }
  return ans;
}

namespace {
std::vector<std::vector<int>> mergeSortedIntervals(std::vector<std::vector<int>> &intervals) {
  std::vector<std::vector<int>> ans = {intervals[0]};
  for (int i = 1; i < static_cast<int>(intervals.size()); ++i) {
    if (auto &&last = ans.back(); intervals[i][0] <= last[1]) {
      last[1] = std::max(last[1], intervals[i][1]);
    } else {
      ans.push_back(intervals[i]);
    }
  }
  return ans;
}
}  // namespace

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) {
  std::sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) { return a[0] < b[0]; });
  return mergeSortedIntervals(intervals);
}

std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval) {
  if (intervals.empty()) {
    return {newInterval};
  }

  // Insert newInterval in correct position
  int i = 0;
  intervals.reserve(intervals.size() + 1);
  while (i < static_cast<int>(intervals.size()) && newInterval[0] > intervals[i][0]) {
    ++i;
  }
  intervals.insert(intervals.begin() + i, newInterval);

  return mergeSortedIntervals(intervals);
}

int findMinArrowShots(std::vector<std::vector<int>> &points) {
  std::sort(points.begin(), points.end(), [](const auto &a, const auto &b) { return a[1] < b[1]; });
  int ans = 1;
  int last = points[0][1];
  for (int i = 1; i < static_cast<int>(points.size()); ++i) {
    if (points[i][0] > last) {
      last = points[i][1];
      ++ans;
    }
  }
  return ans;
}

}  // namespace intervals
