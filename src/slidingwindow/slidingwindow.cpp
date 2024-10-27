#include "slidingwindow/slidingwindow.h"

#include <limits>
#include <unordered_map>

namespace slidingwindow {
int minSubArrayLen(int target, std::vector<int> &nums) {
  int left = 0;
  int right = 0;
  int currentSum = 0;
  int len = static_cast<int>(nums.size());
  int minLength = std::numeric_limits<int>::max();
  while (right < len) {
    currentSum += nums[right++];
    while (currentSum >= target) {
      minLength = std::min(minLength, right - left);
      currentSum -= nums[left++];
    }
  }
  return minLength == std::numeric_limits<int>::max() ? 0 : minLength;
}

int lengthOfLongestSubstring(std::string s) {
  std::unordered_map<char, int> charMap = {};
  int left = 0;
  int right = 0;
  int len = static_cast<int>(s.size());
  int maxLength = 0;

  while (right < len) {
    if (const auto &it = charMap.find(s[right]); it != charMap.end()) {
      maxLength = std::max(maxLength, right - left);
      left = std::max(left, it->second + 1);
    }
    charMap[s[right]] = right;
    ++right;
  }

  maxLength = std::max(maxLength, right - left);
  return maxLength;
}

std::vector<int> findSubstring(std::string s, std::vector<std::string> &words) {
  std::vector<int> result;
  const int wordLen = static_cast<int>(words[0].size());
  const int wordCount = static_cast<int>(words.size());
  const int totalLen = wordLen * wordCount;
  const int sLen = static_cast<int>(s.size());

  if (sLen < totalLen) {
    return result;
  }

  std::unordered_map<std::string_view, int> wordFreq;
  for (const auto &word : words) {
    ++wordFreq[word];
  }

  for (int i = 0; i < wordLen; ++i) {
    int left = i;
    int count = 0;
    std::unordered_map<std::string_view, int> currentFreq;

    for (int right = i; right <= sLen - wordLen; right += wordLen) {
      std::string_view currentWord(s.data() + right, wordLen);

      if (wordFreq.count(currentWord) == 0) {
        currentFreq.clear();
        count = 0;
        left = right + wordLen;
        continue;
      }

      ++currentFreq[currentWord];
      ++count;

      while (currentFreq[currentWord] > wordFreq[currentWord]) {
        std::string_view leftWord(s.data() + left, wordLen);
        --currentFreq[leftWord];
        --count;
        left += wordLen;
      }

      if (count == wordCount) {
        result.push_back(left);
        std::string_view leftWord(s.data() + left, wordLen);
        --currentFreq[leftWord];
        --count;
        left += wordLen;
      }
    }
  }

  return result;
}

std::string minWindow(std::string s, std::string t) {
  if (s.length() < t.length()) {
    return "";
  }

  int left = 0;
  int sLen = static_cast<int>(s.length());
  int tLen = static_cast<int>(t.length());
  int count = 0;
  int minLen = std::numeric_limits<int>::max();
  int resultStart = 0;

  std::vector<int> tFreq(128, 0);
  std::vector<int> currentFreq(128, 0);

  for (const auto &c : t) {
    ++tFreq[c];
  }

  for (int right = 0; right < sLen; ++right) {
    if (tFreq[s[right]] == 0) {
      continue;
    }

    ++currentFreq[s[right]];
    if (currentFreq[s[right]] <= tFreq[s[right]]) {
      ++count;
    }

    while (count == tLen) {
      if (right - left + 1 < minLen) {
        minLen = right - left + 1;
        resultStart = left;
      }

      if (tFreq[s[left]] > 0) {
        if (currentFreq[s[left]] <= tFreq[s[left]]) {
          --count;
        }
        --currentFreq[s[left]];
      }
      ++left;
    }
  }

  return minLen == std::numeric_limits<int>::max() ? "" : s.substr(resultStart, minLen);
}
}  // namespace slidingwindow
