#include "math/math.h"

namespace math {

bool isPalindrome(int number) {
  if (number < 0) {
    return false;
  }
  long original = number;
  long reversed = 0;
  while (number != 0) {
    reversed = reversed * 10 + number % 10;
    number /= 10;
  }
  return original == reversed;
}

std::vector<int> plusOne(std::vector<int> &digits) {
  int n = digits.size();
  for (int i = n - 1; i >= 0; --i) {
    if (digits[i] < 9) {
      digits[i]++;
      return digits;
    }
    digits[i] = 0;
  }

  digits.insert(digits.begin(), 1);
  return digits;
}

int trailingZeroes(int n) {
  int count = 0;
  for (int i = 5; i <= n; i *= 5) {
    count += n / i;
  }
  return count;
}

int mySqrt(int x) {
  if (x == 0) {
    return 0;
  }
  int left = 1;
  int right = x;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (mid == x / mid) {
      return mid;
    } else if (mid < x / mid) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return right;
}

namespace {

double myPowHelper(double x, long long n) {
  if (n == 0) {
    return 1.0;
  }
  double half = myPowHelper(x, n / 2);
  if (n % 2 == 0) {
    return half * half;
  }
  return half * half * x;
}

}  // namespace

double myPow(double x, int n) {
  if (n == 0) {
    return 1;
  }
  if (n < 0) {
    return 1 / myPowHelper(x, -n);
  }
  return myPowHelper(x, n);
}

int maxPoints(std::vector<std::vector<int>> &points) {
  int n = points.size();
  if (n <= 2) {
    return n;
  }
  int max_count = 2;
  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      int count = 2;
      for (int k = j + 1; k < n; ++k) {
        if ((points[j][1] - points[i][1]) * (points[k][0] - points[i][0]) ==
            (points[k][1] - points[i][1]) * (points[j][0] - points[i][0])) {
          ++count;
        }
      }
      max_count = std::max(max_count, count);
    }
  }
  return max_count;
}
}  // namespace math
