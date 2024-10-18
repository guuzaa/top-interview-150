#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <vector>

namespace array {
/// @brief Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
/// @param nums1 The first sorted array.
/// @param m The number of elements in nums1.
/// @param nums2 The second sorted array.
/// @param n The number of elements in nums2.
/// @note https://leetcode.com/problems/merge-sorted-array/
void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n);

/// @brief Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
/// Change the array nums such that the first k elements of nums contain the elements which are not equal to val.
/// The relative order of the elements may be changed.
/// @param nums The integer array.
/// @param val The integer to remove.
/// @return the number of elements in `nums` that are not equal to `val`.
/// @note https://leetcode.com/problems/remove-element/
int removeElement(std::vector<int> &nums, int val);

/// @brief Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each
/// unique element appears only once. The relative order of the elements should be kept the same.
/// @param nums The integer array.
/// @return The number of unique elements in nums.
///
/// constraints
/// - 1 <= nums.length <= 3 * 10^4
/// - -100 <= nums[i] <= 100
/// - nums is sorted in non-decreasing order.
/// @note https://leetcode.com/problems/remove-duplicates-from-sorted-array/
int removeDuplicates(std::vector<int> &nums);

/// @brief Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each
/// unique element appears at most twice. The relative order of the elements should be kept the same.
/// @param nums The integer array.
/// @return The number of unique elements in nums.
///
/// constraints
/// - 1 <= nums.length <= 3 * 10^4
/// - -10^4 <= nums[i] <= 10^4
/// - nums is sorted in non-decreasing order.
/// @note https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
int removeDuplicates2(std::vector<int> &nums);

/// @brief Given an array nums of size n, return the majority element.
/// The majority element is the element that appears more than ⌊n / 2⌋ times.
/// You may assume that the majority element always exists in the array.
/// @param nums The integer array.
/// @return The majority element.
///
/// constraints
/// - 1 <= nums.length <= 5 * 10^4
/// - -10^9 <= nums[i] <= 10^9
/// @note https://leetcode.com/problems/majority-element/
int majorityElement(std::vector<int> &nums);

/// @brief Given an array, rotate the array to the right by k steps, where k is non-negative.
/// @param nums The integer array.
/// @param k The number of steps to rotate.
///
/// constraints
/// - 1 <= nums.length <= 10^5
/// - -2^31 <= nums[i] <= 2^31 - 1
/// - 0 <= k <= 10^5
/// @note https://leetcode.com/problems/rotate-array/
void rotate(std::vector<int> &nums, int k);

/// @brief You are given an array prices where prices[i] is the price of a given stock on the ith day.
/// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
/// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
/// @param prices The integer array.
/// @return The maximum profit.
///
/// constraints
/// - 1 <= prices.length <= 10^5
/// - 0 <= prices[i] <= 10^4
/// @note https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
int maxProfit(std::vector<int> &prices);

/// @brief You are given an array prices where prices[i] is the price of a given stock on the ith day.
/// You can only hold at most one share of the stock at any time.
/// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
/// @param prices The integer array.
/// @return The maximum profit.
///
/// constraints
/// - 1 <= prices.length <= 3 * 10^4
/// - 0 <= prices[i] <= 10^4
/// @note https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
int maxProfit2(std::vector<int> &prices);
}  // namespace array

#endif  //__ARRAY_H__