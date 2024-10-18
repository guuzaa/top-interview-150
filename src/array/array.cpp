#include "array/array.h"
#include <algorithm>
#include <unordered_map>

namespace array {

namespace {
int removeDuplicatesHelper(std::vector<int> &nums, unsigned int k) {
  if (nums.size() <= k) {
    return nums.size();
  }
  int cnt = k;
  for (int i = k; i < static_cast<int>(nums.size()); ++i) {
    if (nums[i] != nums[cnt - k]) {
      nums[cnt] = nums[i];
      cnt += 1;
    }
  }
  return cnt;
}
}  // namespace

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
  int i = m - 1;
  int j = n - 1;
  int cur = m + n - 1;
  while (i >= 0 && j >= 0) {
    if (nums1[i] >= nums2[j]) {
      nums1[cur] = nums1[i];
      i -= 1;
    } else {
      nums1[cur] = nums2[j];
      j -= 1;
    }
    cur -= 1;
  }
  while (j >= 0) {
    nums1[cur] = nums2[j];
    j -= 1;
    cur -= 1;
  }
}

int removeElement(std::vector<int> &nums, int val) {
  int i = 0;
  for (int j = 0; j < static_cast<int>(nums.size()); j++) {
    if (nums[j] != val) {
      nums[i] = nums[j];
      i += 1;
    }
  }
  return i;
}

int removeDuplicates(std::vector<int> &nums) { return removeDuplicatesHelper(nums, 1); }

int removeDuplicates2(std::vector<int> &nums) { return removeDuplicatesHelper(nums, 2); }

int majorityElement(std::vector<int> &nums) {
  int ret = nums[0];
  int cnt = 1;
  for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
    if (nums[i] == ret) {
      cnt += 1;
    } else {
      cnt -= 1;
      if (cnt == 0) {
        cnt = 1;
        ret = nums[i];
      }
    }
  }
  return ret;
}

void rotate(std::vector<int> &nums, int k) {
  int n = static_cast<int>(nums.size());
  if (n == 0 || k == 0) {
    return;
  }

  k %= n;
  if (k == 0) {
    return;
  }
  std::reverse(nums.begin(), nums.end());
  std::reverse(nums.begin(), nums.begin() + k);
  std::reverse(nums.begin() + k, nums.end());
}

int maxProfit(std::vector<int> &prices) {
  int max_profit = 0;
  int min_price = prices[0];
  for (int i = 1; i < static_cast<int>(prices.size()); ++i) {
    if (prices[i] < min_price) {
      min_price = prices[i];
    } else {
      max_profit = std::max(max_profit, prices[i] - min_price);
    }
  }
  return max_profit;
}
}  // namespace array
