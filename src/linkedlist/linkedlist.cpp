#include "linkedlist/linkedlist.h"

#include <unordered_map>

namespace linkedlist {

namespace {

ListNode *getMiddleNode(ListNode *head) {
  ListNode *prev = nullptr;
  auto slow = head;
  auto fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  if (prev != nullptr) {
    prev->next = nullptr;
  }
  return slow;
}

ListNode *mergeKListsHelper(std::vector<ListNode *> &lists, int left, int right) {
  if (left == right) {
    return lists[left];
  }

  int mid = left + (right - left) / 2;
  auto leftList = mergeKListsHelper(lists, left, mid);
  auto rightList = mergeKListsHelper(lists, mid + 1, right);
  return mergeTwoLists(leftList, rightList);
}

}  // namespace

bool hasCycle(ListNode *head) {
  if (head == nullptr) {
    return false;
  }

  auto slow = head;
  auto fast = head->next;
  while (slow != fast) {
    if (fast == nullptr || fast->next == nullptr) {
      return false;
    }
    slow = slow->next;
    fast = fast->next->next;
  }
  return true;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode dummy(0);
  auto curr = &dummy;
  int carry = 0;
  while (l1 != nullptr || l2 != nullptr) {
    int x = l1 != nullptr ? l1->val : 0;
    int y = l2 != nullptr ? l2->val : 0;
    int sum = x + y + carry;
    carry = sum / 10;
    curr->next = new ListNode(sum % 10);
    curr = curr->next;

    if (l1 != nullptr) {
      l1 = l1->next;
    }
    if (l2 != nullptr) {
      l2 = l2->next;
    }
  }

  if (carry > 0) {
    curr->next = new ListNode(carry);
  }

  return dummy.next;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  ListNode dummy(0);
  auto curr = &dummy;
  while (list1 != nullptr && list2 != nullptr) {
    if (list1->val < list2->val) {
      curr->next = list1;
      list1 = list1->next;
    } else {
      curr->next = list2;
      list2 = list2->next;
    }
    curr = curr->next;
  }
  curr->next = list1 != nullptr ? list1 : list2;
  return dummy.next;
}

Node *copyRandomList(Node *head) {
  std::unordered_map<Node *, Node *> map;
  Node dummy(0);
  auto curr = &dummy;
  while (head != nullptr) {
    map[head] = new Node(*head);
    curr->next = map[head];
    curr = curr->next;
    head = head->next;
  }

  head = dummy.next;
  while (head != nullptr) {
    head->random = map[head->random];
    head = head->next;
  }
  return dummy.next;
}

ListNode *reverseBetween(ListNode *head, int left, int right) {
  int pos = 0;
  ListNode dummy(0, head);
  auto prev = &dummy;
  while (pos < left - 1) {
    prev = prev->next;
    ++pos;
  }

  auto curr = prev->next;
  for (int i = 0; i < right - left; ++i) {
    auto nxt = curr->next;
    curr->next = nxt->next;
    nxt->next = prev->next;
    prev->next = nxt;
  }

  return dummy.next;
}

ListNode *reverseList(ListNode *head) {
  ListNode *prev = nullptr;
  while (head != nullptr) {
    auto nxt = head->next;
    head->next = prev;
    prev = head;
    head = nxt;
  }
  return prev;
}

ListNode *reverseKGroup(ListNode *head, int k) {
  if (head == nullptr || k == 1) {
    return head;
  }

  int cnt = 0;
  auto curr = head;
  while (curr != nullptr) {
    curr = curr->next;
    ++cnt;
  }

  ListNode dummy(0, head);
  auto prev = &dummy;
  curr = head;

  while (cnt >= k) {
    auto nextHead = curr;
    for (int i = 0; i < k; i++) {
      nextHead = nextHead->next;
    }

    ListNode *prevNode = nextHead;
    auto currNode = curr;
    for (int i = 0; i < k; i++) {
      auto next = currNode->next;
      currNode->next = prevNode;
      prevNode = currNode;
      currNode = next;
    }

    prev->next = prevNode;
    prev = curr;
    curr = nextHead;
    cnt -= k;
  }

  return dummy.next;
}

ListNode *rotateRight(ListNode *head, int k) {
  if (head == nullptr || k == 0) {
    return head;
  }

  int n = 1;
  auto last = head;
  while (last->next != nullptr) {
    last = last->next;
    n++;
  }

  k = k % n;
  if (k == 0) {
    return head;
  }

  ListNode dummy(0, head);
  auto curr = &dummy;
  for (int i = 0; i < n - k; i++) {
    curr = curr->next;
  }

  auto newHead = curr->next;
  curr->next = nullptr;
  last->next = head;
  return newHead;
}

ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode dummy(0, head);
  auto curr = head;
  int cnt = 1;
  while (curr->next != nullptr) {
    curr = curr->next;
    ++cnt;
  }

  auto prev = &dummy;
  curr = head;
  for (int i = 0; i < cnt - n; i++) {
    prev = prev->next;
    curr = curr->next;
  }

  prev->next = curr->next;
  return dummy.next;
}

ListNode *deleteDuplicates(ListNode *head) {
  if (head == nullptr) {
    return nullptr;
  }

  ListNode dummy(0, head);
  auto prev = &dummy;
  auto curr = head;

  while (curr != nullptr && curr->next != nullptr) {
    if (int val = curr->val; val == curr->next->val) {
      while (curr != nullptr && curr->val == val) {
        curr = curr->next;
      }
      prev->next = curr;
    } else {
      prev = curr;
      curr = curr->next;
    }
  }

  return dummy.next;
}

ListNode *partition(ListNode *head, int x) {
  ListNode leftDummy(0);
  ListNode rightDummy(0);
  auto left = &leftDummy;
  auto right = &rightDummy;
  while (head != nullptr) {
    if (head->val < x) {
      left->next = head;
      left = left->next;
    } else {
      right->next = head;
      right = right->next;
    }
    head = head->next;
  }

  left->next = rightDummy.next;
  right->next = nullptr;
  return leftDummy.next;
}

void LRUCache::moveToFront(CacheNode *node) {
  if (node == head_) {
    return;
  }

  // Remove from current position
  node->prev->next = node->next;
  if (node->next != nullptr) {
    node->next->prev = node->prev;
  } else {
    tail_ = node->prev;
  }

  // Move to front
  node->next = head_;
  node->prev = nullptr;
  head_->prev = node;
  head_ = node;
}

void LRUCache::addToFront(CacheNode *node) {
  if (head_ == nullptr) {
    head_ = tail_ = node;
    return;
  }

  node->next = head_;
  head_->prev = node;
  head_ = node;
}

void LRUCache::removeLRU() {
  if (tail_ == nullptr) {
    return;
  }

  cache_.erase(tail_->key);
  CacheNode *temp = tail_;
  tail_ = tail_->prev;
  if (tail_ != nullptr) {
    tail_->next = nullptr;
  } else {
    head_ = nullptr;
  }
  delete temp;
}

LRUCache::LRUCache(int capacity) : capacity_(capacity), head_(nullptr), tail_(nullptr) {}

LRUCache::~LRUCache() {
  while (head_) {
    CacheNode *temp = head_;
    head_ = head_->next;
    delete temp;
  }
}

int LRUCache::get(int key) {
  if (auto it = cache_.find(key); it != cache_.end()) {
    moveToFront(it->second);
    return it->second->value;
  }
  return -1;
}

void LRUCache::put(int key, int value) {
  if (auto it = cache_.find(key); it != cache_.end()) {
    it->second->value = value;
    moveToFront(it->second);
    return;
  }

  auto *node = new CacheNode(key, value);
  cache_[key] = node;
  addToFront(node);

  if (static_cast<int>(cache_.size()) > capacity_) {
    removeLRU();
  }
}

ListNode *sortList(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  auto mid = getMiddleNode(head);
  auto left = sortList(head);
  auto right = sortList(mid);
  return mergeTwoLists(left, right);
}

ListNode *mergeKLists(std::vector<ListNode *> &lists) {
  if (lists.empty()) {
    return nullptr;
  }

  return mergeKListsHelper(lists, 0, lists.size() - 1);
}

}  // namespace linkedlist
