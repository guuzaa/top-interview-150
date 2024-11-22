#include "bit/bit.h"

#include <numeric>

namespace bit {

std::string addBinary(std::string a, std::string b) {
  std::string result;
  int i = static_cast<int>(a.size()) - 1;
  int j = static_cast<int>(b.size()) - 1;
  int carry = 0;
  while (i >= 0 || j >= 0 || carry > 0) {
    int sum = carry;
    if (i >= 0) {
      sum += a[i--] - '0';
    }
    if (j >= 0) {
      sum += b[j--] - '0';
    }
    result.insert(result.begin(), sum % 2 + '0');
    carry = sum / 2;
  }
  return result;
}

uint32_t reverseBits(uint32_t n) {
  constexpr int bitWidth = sizeof(n) * 8;
  uint32_t result = 0;
  for (int i = 0; i < bitWidth; ++i) {
    result = (result << 1) | (n & 1);
    n >>= 1;
  }
  return result;
}

int hammingWeight(uint32_t n) {
  int count = 0;
  while (n != 0) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

int singleNumber(std::vector<int> &nums) { return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>()); }

int singleNumber2(std::vector<int> &nums) {
  int ones = 0, twos = 0;
  for (int num : nums) {
    // Add num to twos if it's already in ones
    twos |= ones & num;

    // XOR num with ones
    ones ^= num;

    // Clear bits that appear in both ones and twos
    int commonMask = ~(ones & twos);
    ones &= commonMask;
    twos &= commonMask;
  }
  return ones;
}

int rangeBitwiseAnd(int left, int right) {
  int shift = 0;
  while (left != right) {
    left >>= 1;
    right >>= 1;
    ++shift;
  }
  return left << shift;
}

}  // namespace bit
