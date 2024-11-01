#include "stack/stack.h"

#include <optional>
#include <stack>
#include <stdexcept>

namespace stack {

bool isValid(std::string s) {
  auto correspondingBrackets = [](char c) -> std::optional<char> {
    switch (c) {
      case ')':
        return '(';
      case ']':
        return '[';
      case '}':
        return '{';
      default:
        return std::nullopt;
    }
  };

  std::stack<char> brackets;

  for (char c : s) {
    auto leftBracket = correspondingBrackets(c);
    if (!leftBracket.has_value()) {
      brackets.push(c);
    } else {
      if (brackets.empty() || brackets.top() != leftBracket.value()) {
        return false;
      }
      brackets.pop();
    }
  }

  return brackets.empty();
}

std::string simplifyPath(std::string path) {
  std::stack<std::string> paths;
  std::string dir;
  dir.reserve(path.size());

  // Single pass through string, building directory names directly
  for (size_t i = 0; i < path.size(); ++i) {
    if (path[i] != '/') {
      dir += path[i];
      continue;
    }
    if (dir.empty()) {
      continue;
    }

    if (dir == "..") {
      if (!paths.empty()) {
        paths.pop();
      }
    } else if (dir != ".") {
      paths.push(std::move(dir));
    }
    dir.clear();
  }

  // Handle last directory if exists
  if (!dir.empty()) {
    if (dir == "..") {
      if (!paths.empty()) {
        paths.pop();
      }
    } else if (dir != ".") {
      paths.push(std::move(dir));
    }
  }

  if (paths.empty()) {
    return "/";
  }

  std::string result;
  while (!paths.empty()) {
    result = "/" + paths.top() + result;
    paths.pop();
  }
  return result;
}

void MinStack::push(int val) {
  stack_.push(val);
  if (min_stack_.empty() || val <= min_stack_.top()) {
    min_stack_.push(val);
  }
}

void MinStack::pop() {
  if (stack_.top() == min_stack_.top()) {
    min_stack_.pop();
  }
  stack_.pop();
}

int MinStack::top() { return stack_.top(); }

int MinStack::getMin() { return min_stack_.top(); }

namespace {

bool isOperator(const std::string &token) { return token == "+" || token == "-" || token == "*" || token == "/"; }

int applyOperator(int lhs, int rhs, const std::string &op) {
  switch (op[0]) {
    case '+':
      return lhs + rhs;
    case '-':
      return lhs - rhs;
    case '*':
      return lhs * rhs;
    case '/':
      return lhs / rhs;
    default:
      throw std::invalid_argument("Invalid operator: " + op);
  }
}

}  // namespace

int evalRPN(std::vector<std::string> &tokens) {
  std::stack<int> stack;
  for (auto &&token : tokens) {
    if (isOperator(token)) {
      int rhs = stack.top();
      stack.pop();
      int lhs = stack.top();
      stack.pop();
      stack.push(applyOperator(lhs, rhs, token));
    } else {
      stack.push(std::stoi(token));
    }
  }
  return stack.top();
}

int calculate(std::string s) {
  std::stack<int> nums;
  std::stack<char> ops;
  int num = 0;
  int sign = 1;
  int result = 0;

  for (size_t i = 0; i < s.length(); i++) {
    char c = s[i];
    if (isdigit(c)) {
      num = num * 10 + (c - '0');
    } else if (c == '+' || c == '-') {
      result += sign * num;
      num = 0;
      sign = (c == '+') ? 1 : -1;
    } else if (c == '(') {
      nums.push(result);
      ops.push(sign);
      result = 0;
      sign = 1;
    } else if (c == ')') {
      result += sign * num;
      num = 0;
      result = nums.top() + ops.top() * result;
      nums.pop();
      ops.pop();
    }
  }

  return result + sign * num;
}

}  // namespace stack
