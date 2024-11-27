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

int minimumTotal(std::vector<std::vector<int>> &triangle) {
  int n = triangle.size();
  std::vector<std::vector<int>> minSum(n, std::vector<int>(n, 0));
  minSum[0][0] = triangle[0][0];
  for (int i = 1; i < n; ++i) {
    minSum[i][0] = minSum[i - 1][0] + triangle[i][0];
    for (int j = 1; j < i; ++j) {
      minSum[i][j] = std::min(minSum[i - 1][j - 1], minSum[i - 1][j]) + triangle[i][j];
    }
    minSum[i][i] = minSum[i - 1][i - 1] + triangle[i][i];
  }
  return *std::min_element(minSum[n - 1].begin(), minSum[n - 1].end());
}

int minPathSum(std::vector<std::vector<int>> &grid) {
  int m = grid.size();
  int n = grid[0].size();
  std::vector<std::vector<int>> minSum(m, std::vector<int>(n));
  minSum[0][0] = grid[0][0];
  for (int i = 1; i < m; ++i) {
    minSum[i][0] = minSum[i - 1][0] + grid[i][0];
  }
  for (int j = 1; j < n; ++j) {
    minSum[0][j] = minSum[0][j - 1] + grid[0][j];
  }

  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      minSum[i][j] = std::min(minSum[i - 1][j], minSum[i][j - 1]) + grid[i][j];
    }
  }
  return minSum[m - 1][n - 1];
}

int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();
  std::vector<std::vector<int>> uniquePaths(m, std::vector<int>(n));
  uniquePaths[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
  for (int i = 1; i < m; ++i) {
    uniquePaths[i][0] = obstacleGrid[i][0] == 0 ? uniquePaths[i - 1][0] : 0;
  }
  for (int j = 1; j < n; ++j) {
    uniquePaths[0][j] = obstacleGrid[0][j] == 0 ? uniquePaths[0][j - 1] : 0;
  }
  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      uniquePaths[i][j] = obstacleGrid[i][j] == 0 ? uniquePaths[i - 1][j] + uniquePaths[i][j - 1] : 0;
    }
  }
  return uniquePaths[m - 1][n - 1];
}

std::string longestPalindrome(std::string s) {
  int n = s.size();
  std::vector<std::vector<bool>> isPalindrome(n, std::vector<bool>(n, false));
  for (int i = 0; i < n; ++i) {
    isPalindrome[i][i] = true;
  }
  int start = 0;
  int maxLength = 1;

  for (int i = 0; i < n - 1; ++i) {
    if (s[i] != s[i + 1]) {
      continue;
    }
    isPalindrome[i][i + 1] = true;
    start = i;
    maxLength = 2;
  }

  for (int len = 3; len <= n; ++len) {
    for (int i = 0; i < n - len + 1; ++i) {
      int j = i + len - 1;
      if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
        isPalindrome[i][j] = true;
        start = i;
        maxLength = len;
      }
    }
  }

  return s.substr(start, maxLength);
}

bool isInterleave(std::string s1, std::string s2, std::string s3) {
  int m = s1.size();
  int n = s2.size();
  int t = s3.size();
  if (m + n != t) {
    return false;
  }

  std::vector<std::vector<bool>> isInterleave(m + 1, std::vector<bool>(n + 1));
  isInterleave[0][0] = true;
  for (int i = 1; i <= m; ++i) {
    isInterleave[i][0] = isInterleave[i - 1][0] && s1[i - 1] == s3[i - 1];
  }
  for (int j = 1; j <= n; ++j) {
    isInterleave[0][j] = isInterleave[0][j - 1] && s2[j - 1] == s3[j - 1];
  }

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      isInterleave[i][j] = (isInterleave[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                           (isInterleave[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
    }
  }
  return isInterleave[m][n];
}

int minDistance(std::string word1, std::string word2) {
  int m = word1.size();
  int n = word2.size();
  std::vector<std::vector<int>> minDistance(m + 1, std::vector<int>(n + 1));
  minDistance[0][0] = 0;
  for (int i = 1; i <= m; ++i) {
    minDistance[i][0] = i;
  }
  for (int j = 1; j <= n; ++j) {
    minDistance[0][j] = j;
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int ins = minDistance[i + 1][j] + 1;
      int del = minDistance[i][j + 1] + 1;
      int rep = minDistance[i][j] + (word1[i] == word2[j] ? 0 : 1);
      minDistance[i + 1][j + 1] = std::min(ins, std::min(del, rep));
    }
  }
  return minDistance[m][n];
}

int maxProfit3(std::vector<int> &prices) {
  int n = prices.size();
  std::vector<int> leftProfits(n, 0);
  std::vector<int> rightProfits(n, 0);
  int minPrice = prices[0];
  for (int i = 1; i < n; ++i) {
    leftProfits[i] = std::max(leftProfits[i - 1], prices[i] - minPrice);
    minPrice = std::min(minPrice, prices[i]);
  }

  int maxPrice = prices[n - 1];
  for (int j = n - 2; j >= 0; --j) {
    rightProfits[j] = std::max(rightProfits[j + 1], maxPrice - prices[j]);
    maxPrice = std::max(maxPrice, prices[j]);
  }

  int maxProfit = 0;
  for (int i = 0; i < n; ++i) {
    maxProfit = std::max(maxProfit, leftProfits[i] + rightProfits[i]);
  }
  return maxProfit;
}

int maxProfit4(int k, std::vector<int> &prices) {
  int n = prices.size();
  std::vector<std::vector<std::array<int, 2>>> maxProfit(n, std::vector<std::array<int, 2>>(k + 1, {0, 0}));
  for (int i = 0; i < n; ++i) {
    for (int j = k; j >= 1; --j) {
      if (i == 0) {
        maxProfit[i][j][1] = -prices[i];
        continue;
      }
      // if not hold stock
      maxProfit[i][j][0] = std::max(maxProfit[i - 1][j][0], maxProfit[i - 1][j][1] + prices[i]);
      // if hold stock
      maxProfit[i][j][1] = std::max(maxProfit[i - 1][j][1], maxProfit[i - 1][j - 1][0] - prices[i]);
    }
  }
  return maxProfit[n - 1][k][0];
}

int maximalSquare(std::vector<std::vector<char>> &matrix) {
  int m = matrix.size();
  int n = matrix[0].size();
  std::vector<std::vector<int>> maxSquare(m, std::vector<int>(n));
  int maxArea = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] == '0') {
        maxSquare[i][j] = 0;
        continue;
      }

      if (i == 0 || j == 0) {
        maxSquare[i][j] = 1;
      } else {
        maxSquare[i][j] = std::min({maxSquare[i - 1][j], maxSquare[i][j - 1], maxSquare[i - 1][j - 1]}) + 1;
      }
      maxArea = std::max(maxArea, maxSquare[i][j]);
    }
  }
  return maxArea * maxArea;
}

}  // namespace dp
