#ifndef __HEAP_H__
#define __HEAP_H__

#include <queue>
#include <vector>

namespace heap {

/// @brief Given an integer array nums and an integer k, return the kth largest element in the array.
/// @param nums The input array.
/// @param k The kth largest element to find.
/// @return The kth largest element in the array.
///
/// constraints
///
/// - 1 <= k <= nums.length <= 10^5
///
/// - 10^4 <= nums[i] <= 10^4
///
/// @note https://leetcode.com/problems/kth-largest-element-in-an-array/
int findKthLargest(std::vector<int> &nums, int k);

/// @brief Given two integer arrays nums1 and nums2, return an array of their
/// k smallest pairs.
/// @param nums1 The first input array.
/// @param nums2 The second input array.
/// @param k The number of smallest pairs to return.
/// @return A vector of k smallest pairs.
///
/// constraints
///
/// - 1 <= nums1.length, nums2.length <= 10^5
///
/// - -10^9 <= nums1[i], nums2[i] <= 10^9
///
/// - nums1 and nums2 are sorted in non-decreasing order.
///
/// - 1 <= k <= 10^4
///
/// - k <= nums1.length * nums2.length
///
/// @note https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
std::vector<std::vector<int>> kSmallestPairs(std::vector<int> &nums1, std::vector<int> &nums2, int k);

/// @brief Given a set of projects with their profits and capital requirements,
/// and a maximum number of projects k that can be selected, find the maximum
/// profit that can be achieved.
/// @param k The maximum number of projects that can be selected.
/// @param w The initial capital.
/// @param profits The vector of profits for each project.
/// @param capital The vector of capital requirements for each project.
/// @return The maximum profit that can be achieved.
///
/// constraints
///
/// - 1 <= k <= 10^5
///
/// - 0 <= w <= 10^9
///
/// - n == profits.length
///
/// - n == capital.length
///
/// - 1 <= n <= 10^5
///
/// - 0 <= profits[i] <= 10^4
///
/// - 0 <= capital[i] <= 10^9
///
/// @note https://leetcode.com/problems/ipo/
int findMaximizedCapital(int k, int w, std::vector<int> &profits, std::vector<int> &capital);

/// @brief A class to find the median of a stream of numbers.
///
/// constraints
///
/// - -10^5 <= num <= 10^5
///
/// - At most 5 * 10^4 calls will be made to addNum and findMedian.
///
/// @note https://leetcode.com/problems/find-median-from-data-stream/
class MedianFinder {
 public:
  MedianFinder() = default;
  void addNum(int num);
  double findMedian() const;

 private:
  std::priority_queue<int> small_;
  std::priority_queue<int, std::vector<int>, std::greater<>> large_;
};

}  // namespace heap

#endif  // __HEAP_H__
