#ifndef __MATH_H__
#define __MATH_H__

#include <vector>

namespace math {

/// @brief Given a number, return true if it is a palindrome, false otherwise.
/// @param number The number to check.
/// @return True if the number is a palindrome, false otherwise.
///
/// constraints:
///
/// -2^31 <= number <= 2^31 - 1
///
/// @note https://leetcode.com/problems/palindrome-number/
bool isPalindrome(int number);

/// @brief Given a non-negative integer represented as a digit array, increment
/// the number by one and return the result as a digit array.
/// @param digits The digit array representing the non-negative integer.
/// @return The digit array representing the incremented number.
///
/// constraints:
///
/// 1 <= digits.length <= 100
//
/// 0 <= digits[i] <= 9
///
/// digits does not contain any leading 0's.
///
/// @note https://leetcode.com/problems/plus-one/
std::vector<int> plusOne(std::vector<int> &digits);

/// @brief Given an integer n, return the number of trailing zeroes in n!.
/// @param n The integer to calculate the number of trailing zeroes for.
/// @return The number of trailing zeroes in n!.
///
/// constraints:
///
/// 0 <= n <= 10^4
///
/// @note https://leetcode.com/problems/factorial-trailing-zeroes/
int trailingZeroes(int n);

/// @brief Given a non-negative integer x, return the square root of x rounded
/// down to the nearest integer.
/// @param x The non-negative integer to calculate the square root of.
/// @return The square root of x rounded down to the nearest integer.
///
/// constraints:
///
/// 0 <= x <= 2^31 - 1
///
/// @note https://leetcode.com/problems/sqrtx/
int mySqrt(int x);

/// @brief Implement pow(x, n), which calculates x raised to the power n (i.e.,
/// x^n).
/// @param x The base number.
/// @param n The exponent.
/// @return The result of x raised to the power n.
///
/// constraints:
///
/// -100.0 < x < 100.0
///
/// -2^31 <= n <= 2^31 - 1
///
/// - Either x is not 0 or n is not -2^31.
///
/// - -10^4 <= x^n <= 10^4
///
/// @note https://leetcode.com/problems/powx-n/
double myPow(double x, int n);

/// @brief Given an array of points where points[i] = [xi, yi] represents a point
/// on the X-Y plane, return the maximum number of points that lie on the same
/// straight line.
/// @param points The array of points.
/// @return The maximum number of points that lie on the same straight line.
///
/// constraints:
///
/// 1 <= points.length <= 300
///
/// points[i].length == 2
///
/// -10^4 <= xi, yi <= 10^4
///
/// All the points are unique.
///
/// @note https://leetcode.com/problems/max-points-on-a-line/
int maxPoints(std::vector<std::vector<int>> &points);
}  // namespace math

#endif  // __MATH_H__
