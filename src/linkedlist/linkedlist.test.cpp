#include "linkedlist/linkedlist.h"
#include <gtest/gtest.h>

namespace {

linkedlist::ListNode *vector2LinkedList(const std::vector<int> &nums) {
  if (nums.empty()) {
    return nullptr;
  }

  auto head = new linkedlist::ListNode(nums[0]);
  auto curr = head;
  for (size_t i = 1; i < nums.size(); i++) {
    curr->next = new linkedlist::ListNode(nums[i]);
    curr = curr->next;
  }
  return head;
}

linkedlist::ListNode *vector2LinkedList(const std::vector<int> &nums, int pos) {
  if (nums.empty()) {
    return nullptr;
  }

  auto head = new linkedlist::ListNode();
  head->val = nums[0];

  auto curr = head;
  linkedlist::ListNode *cycleNode = nullptr;
  if (pos == 0) {
    cycleNode = head;
  }

  for (size_t i = 1; i < nums.size(); i++) {
    curr->next = new linkedlist::ListNode();
    curr = curr->next;
    curr->val = nums[i];
    if (static_cast<int>(i) == pos) {
      cycleNode = curr;
    }
  }
  curr->next = cycleNode;
  return head;
}

bool linkedListEqual(const linkedlist::ListNode *l1, const linkedlist::ListNode *l2) {
  while (l1 != nullptr && l2 != nullptr) {
    if (l1->val != l2->val) {
      return false;
    }
    l1 = l1->next;
    l2 = l2->next;
  }
  return l1 == nullptr && l2 == nullptr;
}
}  // namespace

TEST(linkedlistTest, hasCycle) {
  struct TestCase {
    std::vector<int> nums;
    int pos;
    bool want;
  };
  std::vector<TestCase> tests = {
      {{3, 2, 0, -4}, 1, true}, {{1, 2}, 0, true}, {{1}, -1, false}, {{3, 2, 0, -4}, -1, false}, {{}, -1, false},
  };

  for (auto &&test : tests) {
    auto head = vector2LinkedList(test.nums, test.pos);
    EXPECT_EQ(linkedlist::hasCycle(head), test.want);
    freeLinkedLists(head);
  }
}

TEST(linkedlistTest, addTwoNumbers) {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::vector<int> want;
  };
  std::vector<TestCase> tests = {
      {{2, 4, 3}, {5, 6, 4}, {7, 0, 8}},
      {{0}, {0}, {0}},
      {{9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}, {8, 9, 9, 9, 0, 0, 0, 1}},
  };
  for (auto &&test : tests) {
    auto l1 = vector2LinkedList(test.nums1, -1);
    auto l2 = vector2LinkedList(test.nums2, -1);
    auto want = vector2LinkedList(test.want, -1);
    auto result = linkedlist::addTwoNumbers(l1, l2);
    EXPECT_TRUE(linkedListEqual(result, want));
    freeLinkedLists(l1, l2, want, result);
  }
}

TEST(linkedlistTest, mergeTwoLists) {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::vector<int> want;
  };

  std::vector<TestCase> tests = {
      {{1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4}}, {{}, {}, {}}, {{}, {0}, {0}}, {{1}, {0}, {0, 1}}, {{1}, {}, {1}},
  };

  for (auto &&test : tests) {
    auto l1 = vector2LinkedList(test.nums1);
    auto l2 = vector2LinkedList(test.nums2);
    auto want = vector2LinkedList(test.want);
    auto result = linkedlist::mergeTwoLists(l1, l2);
    EXPECT_TRUE(linkedListEqual(result, want));
    freeLinkedLists(want, result);
  }
}

TEST(linkedlistTest, reverseBetween) {
  struct TestCase {
    std::vector<int> nums;
    int left;
    int right;
    std::vector<int> want;
  };

  std::vector<TestCase> tests = {
      {{1, 2, 3, 4, 5}, 2, 4, {1, 4, 3, 2, 5}},
      {{5}, 1, 1, {5}},
  };

  for (auto &&test : tests) {
    auto head = vector2LinkedList(test.nums);
    auto want = vector2LinkedList(test.want);
    auto result = linkedlist::reverseBetween(head, test.left, test.right);
    EXPECT_TRUE(linkedListEqual(result, want));
    freeLinkedLists(want, result);
  }
}

TEST(linkedlistTest, reverseList) {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> want;
  };

  std::vector<TestCase> tests = {
      {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}},
      {{1}, {1}},
      {{}, {}},
  };

  for (auto &&test : tests) {
    auto head = vector2LinkedList(test.nums);
    auto want = vector2LinkedList(test.want);
    auto result = linkedlist::reverseList(head);
    EXPECT_TRUE(linkedListEqual(result, want));
    freeLinkedLists(want, result);
  }
}

TEST(linkedlistTest, reverseKGroup) {
  struct TestCase {
    std::vector<int> nums;
    int k;
    std::vector<int> want;
  };

  std::vector<TestCase> tests = {
      {{1, 2, 3, 4, 5}, 2, {2, 1, 4, 3, 5}},
      {{1, 2, 3, 4, 5}, 3, {3, 2, 1, 4, 5}},
      {{1, 2, 3, 4, 5}, 1, {1, 2, 3, 4, 5}},
      {{1, 2, 3, 4, 5, 6}, 2, {2, 1, 4, 3, 6, 5}},
      {{1}, 1, {1}},
  };

  for (auto &&test : tests) {
    auto head = vector2LinkedList(test.nums);
    auto want = vector2LinkedList(test.want);
    auto result = linkedlist::reverseKGroup(head, test.k);
    EXPECT_TRUE(linkedListEqual(result, want));
    freeLinkedLists(want, result);
  }
}

TEST(linkedlistTest, rotateRight) {
  struct TestCase {
    std::vector<int> nums;
    int k;
    std::vector<int> want;
  };

  std::vector<TestCase> tests = {
      {{1, 2, 3, 4, 5}, 2, {4, 5, 1, 2, 3}},
      {{0, 1, 2}, 4, {2, 0, 1}},
      {{1, 2, 3}, 2000000000, {2, 3, 1}},
      {{1, 2}, 2, {1, 2}},
  };

  for (auto &&test : tests) {
    auto head = vector2LinkedList(test.nums);
    auto want = vector2LinkedList(test.want);
    auto result = linkedlist::rotateRight(head, test.k);
    EXPECT_TRUE(linkedListEqual(result, want));
    freeLinkedLists(want, result);
  }
}

TEST(linkedlistTest, removeNthFromEnd) {
  struct TestCase {
    std::vector<int> nums;
    int n;
    std::vector<int> want;
  };

  std::vector<TestCase> tests = {
      {{1, 2, 3, 4, 5}, 2, {1, 2, 3, 5}},
      {{1}, 1, {}},
      {{1, 2}, 1, {1}},
  };

  for (auto &&test : tests) {
    auto head = vector2LinkedList(test.nums);
    auto want = vector2LinkedList(test.want);
    auto result = linkedlist::removeNthFromEnd(head, test.n);
    EXPECT_TRUE(linkedListEqual(result, want));
    freeLinkedLists(want, result);
  }
}

TEST(linkedlistTest, deleteDuplicates) {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> want;
  };

  std::vector<TestCase> tests = {
      {{1, 1, 2}, {2}}, {{1, 1, 1, 1}, {}}, {{1, 2, 3, 3, 4, 4, 5}, {1, 2, 5}}, {{1, 1, 2, 3, 3}, {2}}, {{}, {}},
  };

  for (auto &&test : tests) {
    auto head = vector2LinkedList(test.nums);
    auto want = vector2LinkedList(test.want);
    auto result = linkedlist::deleteDuplicates(head);
    EXPECT_TRUE(linkedListEqual(result, want));
    freeLinkedLists(want, result);
  }
}

TEST(linkedlistTest, partition) {
  struct TestCase {
    std::vector<int> nums;
    int x;
    std::vector<int> want;
  };

  std::vector<TestCase> tests = {{{1, 4, 3, 2, 5, 2}, 3, {1, 2, 2, 4, 3, 5}}, {{2, 1}, 2, {1, 2}}, {{}, 1, {}}};

  for (auto &&test : tests) {
    auto head = vector2LinkedList(test.nums);
    auto want = vector2LinkedList(test.want);
    auto result = linkedlist::partition(head, test.x);
    EXPECT_TRUE(linkedListEqual(result, want));
    freeLinkedLists(want, result);
  }
}

TEST(linkedlistTest, LRUCache) {
  linkedlist::LRUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  EXPECT_EQ(cache.get(1), 1);
  cache.put(3, 3);
  EXPECT_EQ(cache.get(2), -1);
  cache.put(4, 4);
  EXPECT_EQ(cache.get(1), -1);
  EXPECT_EQ(cache.get(3), 3);
  EXPECT_EQ(cache.get(4), 4);
}

TEST(linkedlistTest, sortList) {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> want;
  };
  std::vector<TestCase> tests = {
      {{4, 2, 1, 3}, {1, 2, 3, 4}},
      {{-1, 5, 3, 4, 0}, {-1, 0, 3, 4, 5}},
      {{}, {}},
  };
  for (auto &&test : tests) {
    auto head = vector2LinkedList(test.nums);
    auto want = vector2LinkedList(test.want);
    auto result = linkedlist::sortList(head);
    EXPECT_TRUE(linkedListEqual(result, want));
    freeLinkedLists(want, result);
  }
}

TEST(linkedlistTest, mergeKLists) {
  struct TestCase {
    std::vector<std::vector<int>> lists;
    std::vector<int> want;
  };
  std::vector<TestCase> tests = {
      {{{1, 4, 5}, {1, 3, 4}, {2, 6}}, {1, 1, 2, 3, 4, 4, 5, 6}},
  };
  for (auto &&test : tests) {
    std::vector<linkedlist::ListNode *> lists;
    for (auto &&list : test.lists) {
      lists.push_back(vector2LinkedList(list));
    }
    auto want = vector2LinkedList(test.want);
    auto result = linkedlist::mergeKLists(lists);
    EXPECT_TRUE(linkedListEqual(result, want));
    freeLinkedLists(want, result);
  }
}
