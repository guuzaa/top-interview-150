#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace linkedlist {
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

inline void freeLinkedList(linkedlist::ListNode *head) {
  std::unordered_set<linkedlist::ListNode *> visited;
  while (head != nullptr) {
    if (visited.count(head)) {
      break;
    }
    visited.insert(head);
    auto next = head->next;
    delete head;
    head = next;
  }
}

template <typename... Args>
void freeLinkedLists(Args... args) {
  (freeLinkedList(args), ...);
}

/// @brief given a linked list, determine if it has a cycle in it
/// @param head the head of the linked list
/// @return true if there is a cycle, false otherwise
///
/// constraints:
/// - the number of the nodes in the list is in the range [0, 10^4]
///
/// - -10^5 <= Node.val <= 10^5
///
/// - pos is -1 or a valid index in the linked-list
///
/// @note https://leetcode.com/problems/linked-list-cycle/
bool hasCycle(ListNode *head);

/// @brief add two numbers represented by linked lists. The digits are stored in reverse order
/// @param l1 the first linked list
/// @param l2 the second linked list
/// @return the sum of the two numbers
///
/// constraints:
/// - the number of nodes in each linked list is in the range [1, 100]
///
/// - 0 <= Node.val <= 9
///
/// - it is guaranteed that the list represents a number that does not have leading zeros
///
/// @note https://leetcode.com/problems/add-two-numbers/
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

/// @brief merge two sorted linked lists
/// @param list1 the first linked list
/// @param list2 the second linked list
/// @return the merged linked list
///
/// constraints:
///
/// - the number of nodes in both lists is in the range [0, 50]
///
/// - -100 <= Node.val <= 100
///
/// - both list1 and list2 are sorted in non-decreasing order
///
/// @note https://leetcode.com/problems/merge-two-sorted-lists/
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2);

class Node {
 public:
  int val;
  Node *next;
  Node *random;
  Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
  Node(const Node &other) : val(other.val), next(other.next), random(other.random) {}
};

/// @brief deep-copy a linked list with random pointers
/// @param head the head of the linked list
/// @return the copied linked list
///
/// constraints:
///
/// - -10^4 <= Node.val <= 10^4
///
/// - 0 <= n <= 1000
///
/// @note https://leetcode.com/problems/copy-list-with-random-pointer/
Node *copyRandomList(Node *head);

/// @brief reverse a linked list between two positions
/// @param head the head of the linked list
/// @param left the left position
/// @param right the right position
/// @return the reversed linked list
///
/// constraints:
///
/// - 1 <= left <= right <= n
///
/// - 1 <= n <= 500
///
/// - -500 <= Node.val <= 500
///
/// @note https://leetcode.com/problems/reverse-linked-list-ii/
ListNode *reverseBetween(ListNode *head, int left, int right);

/// @brief reverse the linked list
/// @param head the head of the linked list
/// @return the reversed linked list
///
/// constraints:
///
/// - 0 <= n <= 5000
///
/// - -5000 <= Node.val <= 5000
///
/// @note https://leetcode.com/problems/reverse-linked-list/
ListNode *reverseList(ListNode *head);

/// @brief reverse the nodes of the list k at a time
/// If the number of nodes is not a multiple of k then the nodes that are left out at the end should remain as is.
/// @param head the head of the linked list
/// @param k the number of nodes to reverse
/// @return the reversed linked list
///
/// constraints:
///
/// - 1 <= k <= n <= 5000
///
/// - 0 <= Node.val <= 1000
///
/// @note https://leetcode.com/problems/reverse-nodes-in-k-group/
ListNode *reverseKGroup(ListNode *head, int k);

/// @brief remove the nth node from the end of the list
/// @param head the head of the linked list
/// @param n the nth node to remove
/// @return the modified linked list
///
/// constraints:
///
/// - 1 <= sz <= 30
///
/// - 1 <= n <= sz
///
/// @note https://leetcode.com/problems/remove-nth-node-from-end-of-list/
ListNode *removeNthFromEnd(ListNode *head, int n);

/// @brief remove duplicates from a sorted linked list
/// @param head the head of the linked list
/// @return the modified linked list
///
/// constraints:
///
/// - 0 <= the number of nodes <= 300
///
/// - -100 <= Node.val <= 100
///
/// @note https://leetcode.com/problems/remove-duplicates-from-sorted-list/
ListNode *deleteDuplicates(ListNode *head);

/// @brief rotate the list to the right by k places
/// @param head the head of the linked list
/// @param k the number of places to rotate
/// @return the rotated linked list
///
/// constraints:
///
/// - -100 <= Node.val <= 100
///
/// - 1 <= k <= 2 * 10^9
///
/// @note https://leetcode.com/problems/rotate-list/
ListNode *rotateRight(ListNode *head, int k);

/// @brief partition the linked list such that all nodes less than x come before nodes greater than or equal to x
/// @param head the head of the linked list
/// @param x the partition value
/// @return the partitioned linked list
///
/// constraints:
///
/// - 0 <= sz <= 200
///
/// - -100 <= Node.val <= 100
///
/// - -200 <= x <= 200
///
/// @note https://leetcode.com/problems/partition-list/
ListNode *partition(ListNode *head, int x);

/// @brief LRU cache
///
/// constraints:
///
/// - 1 <= capacity <= 3000
///
/// - 0 <= key <= 10^4
///
/// - 0 <= value <= 10^5
///
/// @note https://leetcode.com/problems/lru-cache/
class LRUCache {
 private:
  struct CacheNode {
    int key;
    int value;
    CacheNode *prev;
    CacheNode *next;
    CacheNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
  };

  int capacity_;
  std::unordered_map<int, CacheNode *> cache_;
  CacheNode *head_;  // Most recently used
  CacheNode *tail_;  // Least recently used

  void moveToFront(CacheNode *node);
  void addToFront(CacheNode *node);
  void removeLRU();

 public:
  explicit LRUCache(int capacity);
  ~LRUCache();

  int get(int key);
  void put(int key, int value);
};

/// @brief sort a linked list in O(n log n) time using constant space complexity
/// @param head the head of the linked list
/// @return the sorted linked list
///
/// constraints:
///
/// - 0 <= sz <= 5 * 10^4
///
/// - -10^5 <= Node.val <= 10^5
///
/// @note https://leetcode.com/problems/sort-list/
ListNode *sortList(ListNode *head);

/// @brief merge k sorted linked lists
/// @param lists the linked lists to merge
/// @return the merged linked list
///
/// constraints:
///
/// - k == lists.length
///
/// - 0 <= k <= 10^4
///
/// - 0 <= lists[i].length <= 500
///
/// - -10^4 <= lists[i][j] <= 10^4
///
/// - lists[i] is sorted in ascending order
///
/// @note https://leetcode.com/problems/merge-k-sorted-lists/
ListNode *mergeKLists(std::vector<ListNode *> &lists);

}  // namespace linkedlist

#endif  // __LINKEDLIST_H__
