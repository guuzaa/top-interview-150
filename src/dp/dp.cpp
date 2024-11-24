#include "dp/dp.h"
#include <array>
#include <unordered_set>

namespace dp {
int climbStairs(int n) {
  if (n <= 2) {
    return n;
  }
  int a = 1;
  int b = 2;
  int c = 0;
  for (int i = 3; i <= n; ++i) {
    c = a + b;
    a = b;
    b = c;
  }
  return b;
}

int rob(std::vector<int> &nums) {
  int n = nums.size();
  std::vector<std::array<int, 2>> maxRobbedAmount(n + 1);
  maxRobbedAmount[0][0] = 0;
  maxRobbedAmount[0][1] = 0;
  for (int i = 1; i <= n; ++i) {
    maxRobbedAmount[i][0] = std::max(maxRobbedAmount[i - 1][0], maxRobbedAmount[i - 1][1]);
    maxRobbedAmount[i][1] = maxRobbedAmount[i - 1][0] + nums[i - 1];
  }
  return std::max(maxRobbedAmount[n][0], maxRobbedAmount[n][1]);
}

bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
  std::unordered_set<std::string_view> wordSet(wordDict.begin(), wordDict.end());
  std::string_view sView(s);
  int n = s.size();
  std::vector<bool> canBreak(n + 1);
  canBreak[0] = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i && !canBreak[i]; ++j) {
      canBreak[i] = canBreak[j] && wordSet.count(sView.substr(j, i - j)) == 1;
    }
  }
  return canBreak[n];
}

int coinChange(std::vector<int> &coins, int amount) {
  std::vector<int> minCoins(amount + 1, amount + 1);
  minCoins[0] = 0;
  for (int i = 1; i <= amount; ++i) {
    for (int coin : coins) {
      if (i - coin < 0) {
        continue;
      }

      minCoins[i] = std::min(minCoins[i], minCoins[i - coin] + 1);
    }
  }
  return minCoins[amount] == amount + 1 ? -1 : minCoins[amount];
}

int lengthOfLIS(std::vector<int> &nums) {
  int n = nums.size();
  std::vector<int> length(n, 1);
  int maxLength = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (nums[i] <= nums[j]) {
        continue;
      }
      length[i] = std::max(length[i], length[j] + 1);
    }
    maxLength = std::max(maxLength, length[i]);
  }
  return maxLength;
}

}  // namespace dp
