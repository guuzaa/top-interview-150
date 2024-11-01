#ifndef __STACK_H__
#define __STACK_H__

#include <stack>
#include <string>
#include <vector>

namespace stack {

/// @brief Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input
/// string is valid.
/// @param s A string containing just the characters '(', ')', '{', '}', '[' and ']'.
/// @return True if the input string is valid, false otherwise.
/// constraints
///
/// - 1 <= s.length <= 10^4
///
/// - s consists of parentheses only '()[]{}'.
///
/// @note https://leetcode.com/problems/valid-parentheses/
bool isValid(std::string s);

/// @brief Given a string path, which is an absolute path (starting with a '/') to a file or directory in a Unix-style
/// file system, convert it to the simplified canonical path.
/// @param path An absolute path to a file or directory in a Unix-style file system.
/// @return The simplified canonical path.
///
/// constraints
///
/// - 1 <= path.length <= 3000
///
/// - path consists of English letters, digits, period '.', slash '/' or '_'.
///
/// - path is a valid absolute Unix path.
///
/// @note https://leetcode.com/problems/simplify-path/
std::string simplifyPath(std::string path);

/// @brief Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
///
/// constraints
///
/// - -2^31 <= val <= 2^31 - 1
///
/// @note https://leetcode.com/problems/min-stack/
class MinStack {
 public:
  MinStack() = default;
  void push(int val);
  void pop();
  int top();
  int getMin();

 private:
  std::stack<int> stack_;
  std::stack<int> min_stack_;
};

/// @brief Evaluate the value of an arithmetic expression in Reverse Polish Notation.
/// @param tokens A vector of strings representing the arithmetic expression in Reverse Polish Notation.
/// @return The value of the arithmetic expression.
///
/// constraints
///
/// - 1 <= tokens.length <= 10^4
///
/// - tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
///
/// @note https://leetcode.com/problems/evaluate-reverse-polish-notation/
int evalRPN(std::vector<std::string> &tokens);

/// @brief Calculate the value of an arithmetic expression in a given string.
/// @param s A string representing the arithmetic expression.
/// @return The value of the arithmetic expression.
///
/// constraints
///
/// - 1 <= s.length <= 3 * 10^5
///
/// - s consists of integers and operators ('+', '-', '(', ')') only.
///
/// @note https://leetcode.com/problems/basic-calculator-ii/
int calculate(std::string s);

}  // namespace stack

#endif  // __STACK_H__
