#ifndef __BINARYSEARCH_H__
#define __BINARYSEARCH_H__

#include <vector>

namespace binarysearch {
/// @brief Given a sorted array of distinct integers and a target value, return the index if the target is found. If
/// not, return the index where it would be if it were inserted in order.
/// @param nums A sorted array of distinct integers.
/// @param target The target value to search for.
/// @return The index of the target if found, otherwise the index where it would be inserted.
/// constraints:
/// - 1 <= nums.length <= 10^4
///
/// - -10^4 <= nums[i] <= 10^4
///
/// - nums contains distinct values sorted in ascending order.
///
/// - -10^4 <= target <= 10^4
///
/// @note https://leetcode.com/problems/search-insert-position/
int searchInsert(std::vector<int> &nums, int target);

/// @brief Write an efficient algorithm that searches for a value target in an m x n integer matrix. This matrix has
/// the following properties:
/// - Integers in each row are sorted from left to right.
/// - The first integer of each row is greater than the last integer of the previous row.
/// @param matrix A 2D integer matrix.
/// @param target The target value to search for.
/// @return True if the target is found, otherwise false.
///
/// constraints:
/// - m == matrix.length
///
/// - n == matrix[i].length
///
/// - 1 <= m, n <= 100
///
/// - -10^4 <= matrix[i][j], target <= 10^4
///
/// @note https://leetcode.com/problems/search-a-2d-matrix/
bool searchMatrix(std::vector<std::vector<int>> &matrix, int target);

/// @brief A peak element is an element that is strictly greater than its neighbors.
/// @param nums A vector of integers.
/// @return The index of the peak element.
///
/// constraints:
/// - 1 <= nums.length <= 1000
///
/// - -2^31 <= nums[i] <= 2^31 - 1
///
/// - nums[i] != nums[i + 1] for all valid i
///
/// @note https://leetcode.com/problems/find-peak-element/
int findPeakElement(std::vector<int> &nums);

/// @brief Given an array of integers nums which is sorted in ascending order, and an integer target, write a function
/// to search target in nums. If target exists, then return its index. Otherwise, return -1.
/// Prior to being passed to your function, nums is rotated at an unknown pivot index k (1 <= k < nums.length) such that
/// the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For
/// example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 to become [4,5,6,7,0,1,2].
/// @param nums A sorted array of integers.
/// @param target The target value to search for.
/// @return The index of the target if found, otherwise -1.
///
/// constraints:
/// - 1 <= nums.length <= 5000
///
/// - -10^4 <= nums[i] <= 10^4
///
/// - All values of nums are unique.
///
/// - nums is guaranteed to be rotated at some pivot.
///
/// @note https://leetcode.com/problems/search-in-rotated-sorted-array/
int search(std::vector<int> &nums, int target);

/// @brief Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a
/// given target value. If target is not found in the array, return [-1, -1].
/// @param nums A sorted array of integers.
/// @param target The target value to search for.
/// @return A vector containing the starting and ending positions of the target value.
///
/// constraints:
/// - 0 <= nums.length <= 10^5
///
/// - -10^9 <= nums[i] <= 10^9
///
/// - nums is sorted in non-decreasing order.
///
/// @note https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
std::vector<int> searchRange(std::vector<int> &nums, int target);

/// @brief Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the
/// array nums = [0,1,2,4,5,6,7] might become:
/// @param nums A sorted array of integers.
/// @return The minimum element in the array.
///
/// constraints:
/// - n == nums.length
///
/// - 1 <= n <= 5000
///
/// - -5000 <= nums[i] <= 5000
///
/// - All the integers of nums are unique.
///
/// - nums is sorted and rotated between 1 and n times.
///
/// @note https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
int findMin(std::vector<int> &nums);

/// @brief Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted
/// arrays.
/// @param nums1 A sorted array of integers.
/// @param nums2 A sorted array of integers.
/// @return The median of the two sorted arrays.
///
/// constraints:
/// - nums1.length == m
///
/// - nums2.length == n
///
/// - 0 <= m <= 1000
///
/// - 0 <= n <= 1000
///
/// - 1 <= m + n <= 2000
///
/// - -10^6 <= nums1[i], nums2[i] <= 10^6
///
/// @note https://leetcode.com/problems/median-of-two-sorted-arrays/
double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2);

}  // namespace binarysearch

#endif  // __BINARYSEARCH_H__