#include "twopointers/twopointers.h"

#include <cctype>

namespace twopointers {

bool isPalindrome(std::string s) {
  int left = 0;
  int right = static_cast<int>(s.size()) - 1;
  while (left < right) {
    if (!std::isalnum(s[left])) {
      ++left;
    } else if (!std::isalnum(s[right])) {
      --right;
    } else if (std::tolower(s[left]) != std::tolower(s[right])) {
      return false;
    } else {
      ++left;
      --right;
    }
  }
  return true;
}

bool isSubsequence(std::string s, std::string t) {
  if (s.size() > t.size()) {
    return false;
  }

  int sIndex = 0;
  int sLen = static_cast<int>(s.size());
  int tLen = static_cast<int>(t.size());
  for (int i = 0; i < tLen && sIndex < sLen; ++i) {
    if (s[sIndex] == t[i]) {
      ++sIndex;
    }
  }
  return sIndex == sLen;
}

std::vector<int> twoSum(std::vector<int> &nums, int target) {
  int left = 0;
  int right = static_cast<int>(nums.size()) - 1;
  while (left < right) {
    int sum = nums[left] + nums[right];
    if (sum == target) {
      return {left + 1, right + 1};
    } else if (sum < target) {
      ++left;
    } else {
      --right;
    }
  }
  return {};
}

int maxArea(std::vector<int> &height) {
  int left = 0;
  int right = static_cast<int>(height.size()) - 1;
  int area = 0;
  while (left < right) {
    area = std::max(area, std::min(height[left], height[right]) * (right - left));
    if (height[left] < height[right]) {
      left += 1;
    } else {
      right -= 1;
    }
  }
  return area;
}

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
  std::sort(nums.begin(), nums.end());
  int len = static_cast<int>(nums.size());
  std::vector<std::vector<int>> result;
  for (int i = 0; i < len - 2; ++i) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }

    int left = i + 1;
    int right = len - 1;
    while (left < right) {
      int sum = nums[left] + nums[right] + nums[i];

      if (sum == 0) {
        result.emplace_back(std::vector<int>{nums[i], nums[left], nums[right]});
        while (left < right && nums[left] == nums[left + 1]) {
          ++left;
        }
        while (left < right && nums[right] == nums[right - 1]) {
          --right;
        }
        ++left;
        --right;
      } else if (sum < 0) {
        ++left;
      } else {
        --right;
      }
    }
  }
  return result;
}
}  // namespace twopointers
