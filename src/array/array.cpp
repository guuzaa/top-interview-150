#include "array/array.h"
#include <algorithm>
#include <array>
#include <random>
#include <unordered_map>

namespace array {

namespace {
int removeDuplicatesHelper(std::vector<int> &nums, int k) {
  int len = static_cast<int>(nums.size());
  if (len <= k) {
    return len;
  }
  int cnt = k;
  for (int i = k; i < len; ++i) {
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
  int candidate = nums[0];
  int cnt = 1;
  for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
    if (nums[i] == candidate) {
      cnt += 1;
    } else {
      cnt -= 1;
      if (cnt == 0) {
        cnt = 1;
        candidate = nums[i];
      }
    }
  }
  return candidate;
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
    max_profit = std::max(max_profit, prices[i] - min_price);
    min_price = std::min(min_price, prices[i]);
  }
  return max_profit;
}

int maxProfit2(std::vector<int> &prices) {
  auto len = static_cast<int>(prices.size());
  // less than 2 days, no profit
  if (len < 2) {
    return 0;
  }

  // dp[i][0] means the max profit on day i without stock
  // dp[i][1] means the max profit on day i with stock
  std::vector<std::array<int, 2>> dp(len);
  dp[0][0] = 0;
  dp[0][1] = -prices[0];
  for (int i = 1; i < len; ++i) {
    dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
    dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
  }
  return dp[len - 1][0];
}

bool canJump(std::vector<int> &nums) {
  int n = static_cast<int>(nums.size());
  int max_reach = 0;
  for (int i = 0; i < n; ++i) {
    if (i > max_reach) {
      return false;
    }
    max_reach = std::max(max_reach, i + nums[i]);
  }
  return true;
}

int jump(std::vector<int> &nums) {
  int n = static_cast<int>(nums.size());
  if (n == 1) {
    return 0;
  }
  int jumps = 0;
  int current_end = 0;
  int farthest = 0;

  for (int i = 0; i < n - 1; ++i) {
    farthest = std::max(farthest, i + nums[i]);
    if (i == current_end) {
      current_end = farthest;
      jumps += 1;
    }
  }
  return jumps;
}

int hIndex(std::vector<int> &citations) {
  std::sort(citations.begin(), citations.end());
  int n = static_cast<int>(citations.size());
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    ret = std::max(ret, std::min(citations[i], n - i));
  }
  return ret;
}

RandomizedSet::RandomizedSet() : gen_(std::random_device{}()), dis_(0, 0) {}

bool RandomizedSet::insert(int val) {
  if (map_.count(val)) {
    return false;
  }
  map_.emplace(val, values_.size());
  values_.push_back(val);
  dis_ = std::uniform_int_distribution<>(0, values_.size() - 1);
  return true;
}

bool RandomizedSet::remove(int val) {
  if (!map_.count(val)) {
    return false;
  }

  int idx = map_[val];
  map_.erase(val);
  if (idx != static_cast<int>(values_.size() - 1)) {
    values_[idx] = values_.back();
    map_[values_.back()] = idx;
  }
  values_.pop_back();
  dis_ = std::uniform_int_distribution<>(0, values_.size() - 1);
  return true;
}

int RandomizedSet::getRandom() { return values_[dis_(gen_)]; }

std::vector<int> productExceptSelf(std::vector<int> &nums) {
  int len = static_cast<int>(nums.size());
  std::vector<int> answers(len);
  int product = 1;
  for (int i = 0; i < len; ++i) {
    answers[i] = product;
    product *= nums[i];
  }
  product = 1;
  for (int i = len - 1; i >= 0; --i) {
    answers[i] *= product;
    product *= nums[i];
  }
  return answers;
}

int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
  int total_tank = 0;
  // if it's negative, it means start from this station or any station before this one will not work
  int curr_tank = 0;
  int starting_station = 0;
  int len = static_cast<int>(gas.size());

  for (int i = 0; i < len; ++i) {
    total_tank += gas[i] - cost[i];
    curr_tank += gas[i] - cost[i];
    if (curr_tank < 0) {
      starting_station = i + 1;
      curr_tank = 0;
    }
  }
  // If the total gas is greater than or equal to the total cost, a solution exists
  return total_tank >= 0 ? starting_station : -1;
}

int candy(std::vector<int> &ratings) {
  int len = static_cast<int>(ratings.size());
  std::vector<int> candies(len, 1);
  for (int i = 1; i < len; ++i) {
    if (ratings[i] > ratings[i - 1]) {
      candies[i] = candies[i - 1] + 1;
    }
  }

  int num_candies = candies[len - 1];
  for (int i = len - 2; i >= 0; --i) {
    if (ratings[i] > ratings[i + 1]) {
      candies[i] = std::max(candies[i], candies[i + 1] + 1);
    }
    num_candies += candies[i];
  }
  return num_candies;
}

int trap(std::vector<int> &height) {
  int len = static_cast<int>(height.size());
  std::vector<int> left_max(len);
  std::vector<int> right_max(len);
  left_max[0] = height[0];
  for (int i = 1; i < len; ++i) {
    left_max[i] = std::max(left_max[i - 1], height[i]);
  }

  right_max[len - 1] = height[len - 1];
  for (int i = len - 2; i >= 0; --i) {
    right_max[i] = std::max(right_max[i + 1], height[i]);
  }

  int water = 0;
  for (int i = 0; i < len; ++i) {
    water += std::min(left_max[i], right_max[i]) - height[i];
  }
  return water;
}

int maxSubArray(std::vector<int> &nums) {
  int maxSoFar = nums[0];
  int maxSum = nums[0];
  for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
    maxSoFar = std::max(maxSoFar + nums[i], nums[i]);
    maxSum = std::max(maxSum, maxSoFar);
  }
  return maxSum;
}

int maxSubarraySumCircular(std::vector<int> &nums) {
  int maxSoFar = nums[0];
  int minSoFar = nums[0];
  int maxSum = nums[0];
  int minSum = nums[0];
  for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
    maxSoFar = std::max(maxSoFar + nums[i], nums[i]);
    minSoFar = std::min(minSoFar + nums[i], nums[i]);
    maxSum = std::max(maxSum, maxSoFar);
    minSum = std::min(minSum, minSoFar);
  }

  int total = std::accumulate(nums.begin(), nums.end(), 0);
  if (total != minSum) {
    return std::max(maxSum, total - minSum);
  }
  return maxSum;
}

}  // namespace array
