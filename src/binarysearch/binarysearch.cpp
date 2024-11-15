#include "binarysearch/binarysearch.h"

#include <concepts>

namespace binarysearch {

namespace {

template <std::totally_ordered T>
int leftBound(std::vector<T> &nums, T target) {
  int left = 0;
  int n = nums.size();
  int right = n;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
      right = mid;
    } else if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  if (left == n || nums[left] != target) {
    return -1;
  }
  return left;
}

template <std::totally_ordered T>
int rightBound(std::vector<T> &nums, T target) {
  int left = 0;
  int n = nums.size();
  int right = n;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
      left = mid + 1;
    } else if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  if (left == 0 || nums[left - 1] != target) {
    return -1;
  }
  return left - 1;
}

}  // namespace

int searchInsert(std::vector<int> &nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (target == nums[mid]) {
      return mid;
    } else if (target > nums[mid]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return left;
}

bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
  int m = static_cast<int>(matrix.size());
  int n = static_cast<int>(matrix[0].size());
  int left = 0;
  int right = m * n - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    int row = mid / n;
    int col = mid % n;
    if (matrix[row][col] == target) {
      return true;
    } else if (matrix[row][col] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return false;
}

int findPeakElement(std::vector<int> &nums) {
  int left = 0;
  int right = nums.size() - 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] > nums[mid + 1]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

int search(std::vector<int> &nums, int target) {
  int left = 0;
  int right = nums.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (nums[mid] == target) {
      return mid;
    }

    // Left half is sorted
    if (nums[left] <= nums[mid]) {
      if (nums[left] <= target && target < nums[mid]) {
        // Target is in the sorted left half
        right = mid - 1;
      } else {
        // Target is in the right half
        left = mid + 1;
      }
    } else {
      if (nums[mid] < target && target <= nums[right]) {
        // Target is in the sorted right half
        left = mid + 1;
      } else {
        // Target is in the left half
        right = mid - 1;
      }
    }
  }
  return -1;
}

std::vector<int> searchRange(std::vector<int> &nums, int target) {
  int left = leftBound(nums, target);
  if (left == -1) {
    return {-1, -1};
  }
  int right = rightBound(nums, target);
  return {left, right};
}

int findMin(std::vector<int> &nums) {
  int left = 0;
  int right = static_cast<int>(nums.size()) - 1;

  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] > nums[right]) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return nums[left];
}

double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
  int m = static_cast<int>(nums1.size());
  int n = static_cast<int>(nums2.size());

  if (m > n) {
    return findMedianSortedArrays(nums2, nums1);  // Ensure nums1 is the smaller array
  }

  int iMin = 0;
  int iMax = m;
  int halfLen = (m + n + 1) / 2;
  double maxOfLeft, minOfRight;

  while (iMin <= iMax) {
    int i = (iMin + iMax) / 2;
    int j = halfLen - i;

    if (i < m && nums2[j - 1] > nums1[i]) {
      iMin = i + 1;
    } else if (i > 0 && nums1[i - 1] > nums2[j]) {
      iMax = i - 1;
    } else {
      if (i == 0) {
        maxOfLeft = nums2[j - 1];
      } else if (j == 0) {
        maxOfLeft = nums1[i - 1];
      } else {
        maxOfLeft = std::max(nums1[i - 1], nums2[j - 1]);
      }

      if ((m + n) % 2 == 1) {
        return maxOfLeft;
      }

      if (i == m) {
        minOfRight = nums2[j];
      } else if (j == n) {
        minOfRight = nums1[i];
      } else {
        minOfRight = std::min(nums1[i], nums2[j]);
      }

      return (maxOfLeft + minOfRight) / 2.0;
    }
  }

  return 0.0;  // Should never be reached
}

}  // namespace binarysearch
