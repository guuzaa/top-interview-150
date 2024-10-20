#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <random>
#include <unordered_map>
#include <vector>

namespace array {
/// @brief Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
/// @param nums1 The first sorted array.
/// @param m The number of elements in nums1.
/// @param nums2 The second sorted array.
/// @param n The number of elements in nums2.
///
/// constraints
/// - 1 <= nums1.length, nums2.length <= 200
/// - 0 <= m, n <= 200
/// - 10^9 <= nums1[i], nums2[j] <= 10^9
/// @note https://leetcode.com/problems/merge-sorted-array/
void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n);

/// @brief Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
/// Change the array nums such that the first k elements of nums contain the elements which are not equal to val.
/// The relative order of the elements may be changed.
/// @param nums The integer array.
/// @param val The integer to remove.
/// @return the number of elements in `nums` that are not equal to `val`.
///
/// constraints
/// - 0 <= nums.length <= 100
/// - 0 <= nums[i] <= 50
/// - 0 <= val <= 100
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
/// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the
/// future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve
/// any profit, return 0.
/// @param prices The integer array.
/// @return The maximum profit.
///
/// constraints
/// - 1 <= prices.length <= 10^5
/// - 0 <= prices[i] <= 10^4
/// @note https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
int maxProfit(std::vector<int> &prices);

/// @brief You are given an array prices where prices[i] is the price of a given stock on the ith day.
/// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any
/// time. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
/// @param prices The integer array.
/// @return The maximum profit.
///
/// constraints
/// - 1 <= prices.length <= 3 * 10^4
/// - 0 <= prices[i] <= 10^4
/// @note https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
int maxProfit2(std::vector<int> &prices);

/// @brief You are given an integer array nums.
/// You are initially positioned at the array's first index, and each element in the array represents your maximum jump
/// length at that position.
/// @param nums The integer array.
/// @return true if you can reach the last index, or false otherwise.
///
/// constraints
/// - 1 <= nums.length <= 10^4
/// - 0 <= nums[i] <= 10^5
/// @note https://leetcode.com/problems/jump-game/
bool canJump(std::vector<int> &nums);

/// @brief You are given an integer array nums.
/// You are initially positioned at the array's first index, and each element in the array represents your maximum jump
/// length at that position.
/// @param nums The integer array.
/// @return The minimum number of jumps to reach the last index.
///
/// constraints
/// - 1 <= nums.length <= 10^4
/// - 0 <= nums[i] <= 1000
/// @note https://leetcode.com/problems/jump-game-ii/
int jump(std::vector<int> &nums);

/// @brief Given an array of integers citations where citations[i] is the number of citations a researcher received
/// for their ith paper, return the researcher's h-index.
/// @param citations The integer array.
/// @return The researcher's h-index.
///
/// constraints
/// - n == citations.length
/// - 1 <= n <= 5000
/// - 0 <= citations[i] <= 1000
/// @note https://leetcode.com/problems/h-index/
int hIndex(std::vector<int> &citations);

/// @brief Design a data structure that supports insert, delete, and getRandom operations.
///
/// constraints
/// - -2^31 <= val <= 2^31 - 1
/// - At most 2 * 10^5 calls will be made to insert, delete, and getRandom.
/// - There will be at least one element in the data structure when getRandom is called.
/// @note https://leetcode.com/problems/insert-delete-getrandom-o1/
class RandomizedSet {
 public:
  RandomizedSet();
  bool insert(int val);
  bool remove(int val);
  int getRandom();

 private:
  std::unordered_map<int, int> map_;
  std::vector<int> values_;
  std::mt19937 gen_;
  std::uniform_int_distribution<> dis_;
};

/// @brief Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the
/// elements of nums except nums[i].
/// @param nums The integer array.
/// @return The integer array.
///
/// constraints
/// - 2 <= nums.length <= 10^5
/// - -30 <= nums[i] <= 30
/// @note https://leetcode.com/problems/product-of-array-except-self/
std::vector<int> productExceptSelf(std::vector<int> &nums);

/// @brief There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
/// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next
/// (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
/// @param gas the amount of gas at the ith station.
/// @param cost the cost of gas to travel from the ith station to its next (i + 1)th station.
/// @return The starting gas station's index if you can travel around the circuit once in the clockwise direction,
/// otherwise return -1.
///
/// constraints
/// - n == gas.length == cost.length
/// - 1 <= n <= 10^5
/// - 0 <= gas[i], cost[i] <= 10^4
/// @note https://leetcode.com/problems/gas-station/
int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost);

/// @brief There are n children standing in a line. Each child is assigned a rating value given in the integer array
/// ratings. You are giving candies to these children subjected to the following requirements:
///
/// - Each child must have at least one candy.
///
/// - Children with a higher rating get more candies than their neighbors.
/// @param ratings The integer array.
/// @return The minimum number of candies you need to have to distribute to the children.
///
/// constraints
///
/// - n == ratings.length
///
/// - 1 <= n <= 2 * 10^4
///
/// - 0 <= ratings[i] <= 2 * 10^4
/// @note https://leetcode.com/problems/candy/
int candy(std::vector<int> &ratings);

/// @brief Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how
/// much water it can trap after raining.
/// @param height The integer array.
/// @return The amount of water it can trap after raining.
///
/// constraints
/// - n == height.length
///
/// - 1 <= n <= 2 * 10^4
///
/// - 0 <= height[i] <= 10^5
/// @note https://leetcode.com/problems/trapping-rain-water/
int trap(std::vector<int> &height);
}  // namespace array

#endif  //__ARRAY_H__
