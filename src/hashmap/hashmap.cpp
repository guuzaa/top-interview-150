#include "hashmap/hashmap.h"

#include <array>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

namespace hashmap {
bool canConstruct(std::string ransomNote, std::string magazine) {
  if (ransomNote.size() > magazine.size()) {
    return false;
  }

  std::array<int, 26> cnt = {};
  for (char ch : magazine) {
    int idx = ch - 'a';
    ++cnt[idx];
  }

  for (char ch : ransomNote) {
    int idx = ch - 'a';
    --cnt[idx];
    if (cnt[idx] < 0) {
      return false;
    }
  }
  return true;
}

bool isIsomorphic(std::string s, std::string t) {
  std::array<int, 128> s2t = {};  // Map s chars to first occurrence in t
  std::array<int, 128> t2s = {};  // Map t chars to first occurrence in s
  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    int sChar = static_cast<int>(s[i]);
    int tChar = static_cast<int>(t[i]);
    if (s2t[sChar] != t2s[tChar]) {
      return false;
    }
    s2t[sChar] = i + 1;
    t2s[tChar] = i + 1;
  }
  return true;
}

bool wordPattern(std::string pattern, std::string s) {
  std::unordered_map<std::string_view, int> s2p;
  std::unordered_map<char, int> p2s;
  std::stringstream ss(s);
  std::string word;
  std::vector<std::string> words;
  while (ss >> word) {
    words.push_back(word);
  }

  if (words.size() != pattern.size()) {
    return false;
  }

  for (int i = 0; i < static_cast<int>(pattern.size()); ++i) {
    char ch = pattern[i];
    std::string_view word{words[i]};

    if (s2p.find(word) == s2p.end()) {
      s2p[word] = i + 1;
    }
    if (p2s.find(ch) == p2s.end()) {
      p2s[ch] = i + 1;
    }
    if (s2p[word] != p2s[ch]) {
      return false;
    }
  }
  return true;
}

bool isAnagram(std::string s, std::string t) {
  std::array<int, 26> cnt = {};
  for (char ch : s) {
    ++cnt[ch - 'a'];
  }
  for (char ch : t) {
    --cnt[ch - 'a'];
  }
  return std::all_of(cnt.begin(), cnt.end(), [](int c) { return c == 0; });
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
  std::unordered_map<std::string, std::vector<std::string>> mp;
  for (const auto &str : strs) {
    std::string sorted = str;
    std::sort(sorted.begin(), sorted.end());
    mp[sorted].push_back(str);
  }

  std::vector<std::vector<std::string>> result;
  result.reserve(mp.size());
  for (auto &&[_, v] : mp) {
    result.push_back(v);
  }
  return result;
}

std::vector<int> twoSum(std::vector<int> &nums, int target) {
  std::unordered_map<int, int> mp;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    int num = nums[i];
    int complement = target - num;
    if (auto it = mp.find(complement); it != mp.end()) {
      return {it->second, i};
    }
    mp.emplace(num, i);
  }
  return {};
}

namespace {
int squares_of_digits(int n) {
  int sum = 0;
  while (n > 0) {
    int digit = n % 10;
    sum += digit * digit;
    n /= 10;
  }
  return sum;
}
}  // namespace

bool isHappy(int n) {
  int slow = n;
  int fast = squares_of_digits(n);
  while (slow != fast) {
    if (fast == 1) {
      return true;
    }
    slow = squares_of_digits(slow);
    fast = squares_of_digits(squares_of_digits(fast));
  }
  return fast == 1;
}

bool containsNearbyDuplicate(std::vector<int> &nums, int k) {
  std::unordered_map<int, int> mp;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    int num = nums[i];
    if (auto it = mp.find(num); it != mp.end()) {
      if (i - it->second <= k) {
        return true;
      }
    }
    mp[num] = i;
  }
  return false;
}

int longestConsecutive(std::vector<int> &nums) {
  int longest = 0;
  std::unordered_map<int, int> mp;
  for (auto num : nums) {
    if (mp.find(num) == mp.end()) {
      int left = 0;
      int right = 0;
      int sum = 0;
      if (mp.find(num - 1) != mp.end()) {
        left = mp[num - 1];
      }
      if (mp.find(num + 1) != mp.end()) {
        right = mp[num + 1];
      }

      sum = left + right + 1;
      mp[num] = sum;
      mp[num - left] = sum;
      mp[num + right] = sum;
      longest = std::max(longest, sum);
    }
  }
  return longest;
}

}  // namespace hashmap
