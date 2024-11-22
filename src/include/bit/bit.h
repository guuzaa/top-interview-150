#ifndef __BIT_H__
#define __BIT_H__

#include <string>
#include <vector>

namespace bit {

/// @brief Given two binary strings a and b, return their sum as a binary string.
/// @param a The first binary string.
/// @param b The second binary string.
/// @return The sum of a and b as a binary string.
/// constraints
/// - 1 <= a.length, b.length <= 10^4
///
/// - a and b consist only of '0' or '1' characters.
///
/// - Each string does not contain leading zeros except for the zero itself.
///
/// @note https://leetcode.com/problems/add-binary/
std::string addBinary(std::string a, std::string b);

/// @brief Reverse bits of a given 32 bits unsigned integer.
/// @param n The 32 bits unsigned integer.
/// @return The reversed 32 bits unsigned integer.
/// constraints
/// - 0 <= n < 2^31 - 1
///
/// @note https://leetcode.com/problems/reverse-bits/
uint32_t reverseBits(uint32_t n);

/// @brief Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the
/// Hamming weight).
/// @param n The unsigned integer.
/// @return The number of '1' bits in n.
/// constraints
/// - The input must be a binary representation of an unsigned integer.
///
/// @note https://leetcode.com/problems/number-of-1-bits/
int hammingWeight(uint32_t n);

/// @brief Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
/// @param nums The non-empty array of integers.
/// @return The single number that appears only once.
/// constraints
/// - 1 <= nums.length <= 3 * 10^4
///
/// - -3 * 10^4 <= nums[i] <= 3 * 10^4
///
/// @note https://leetcode.com/problems/single-number/
int singleNumber(std::vector<int> &nums);

/// @brief Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
/// @param nums The non-empty array of integers.
/// @return The single number that appears only once.
/// constraints
/// - 1 <= nums.length <= 3 * 10^4
///
/// - -2^31 <= nums[i] <= 2^31 - 1
///
/// @note https://leetcode.com/problems/single-number-ii/
int singleNumber2(std::vector<int> &nums);

/// @brief Given two integers left and right that represent the range [left, right], return the bitwise AND of all
/// numbers in this range, inclusive.
/// @param left The left integer.
/// @param right The right integer.
/// @return The bitwise AND of all numbers in the range [left, right].
/// constraints
/// - 0 <= left <= right <= 2^31 - 1
///
/// @note https://leetcode.com/problems/bitwise-and-of-numbers-range/
int rangeBitwiseAnd(int left, int right);

}  // namespace bit

#endif  // __BIT_H__
