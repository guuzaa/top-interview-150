#ifndef __INTERVALS_H__
#define __INTERVALS_H__

#include <string>
#include <vector>

namespace intervals {

/// @brief Given a sorted unique integer array nums, create a smallest possible list of ranges that cover all the
/// numbers in the array exactly.
/// @param nums A sorted unique integer array.
/// @return A smallest possible list of ranges that cover all the numbers in the array exactly.
/// constraints
///
/// - 0 <= nums.length <= 20
///
/// - -2^31 <= nums[i] <= 2^31 - 1
///
/// - All the values of nums are unique.
///
/// - nums is sorted in ascending order.
///
/// @note https://leetcode.com/problems/summary-ranges/
std::vector<std::string> summaryRanges(std::vector<int> &nums);

/// @brief Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and
/// return an array of the non-overlapping intervals that cover all the intervals in the input.
/// @param intervals An array of intervals where intervals[i] = [starti, endi].
/// @return An array of the non-overlapping intervals that cover all the intervals in the input.
/// constraints
///
/// - 1 <= intervals.length <= 10^4
///
/// - intervals[i].length == 2
///
/// - 0 <= starti <= endi <= 10^4
///
/// @note https://leetcode.com/problems/merge-intervals/
std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals);

/// @brief Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
/// @param intervals A set of non-overlapping intervals.
/// @param newInterval The new interval to insert.
/// @return A set of non-overlapping intervals after inserting the new interval.
/// constraints
///
/// - 0 <= intervals.length <= 10^4
///
/// - intervals[i].length == 2
///
/// - 0 <= starti <= endi <= 10^5
///
/// - intervals is sorted by starti in ascending order.
///
/// - newInterval.length == 2
///
/// @note https://leetcode.com/problems/insert-interval/
std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval);

/// @brief Given an array of balloons, find the minimum number of arrows needed to burst all balloons.
/// @param points An array of balloons.
/// @return The minimum number of arrows needed to burst all balloons.
/// constraints
///
/// - 1 <= points.length <= 10^5
///
/// - points[i].length == 2
///
/// - -2^31 <= points[i][0] < points[i][1] <= 2^31 - 1
///
/// @note https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
int findMinArrowShots(std::vector<std::vector<int>> &points);

}  // namespace intervals

#endif  // INTERVALS_H
