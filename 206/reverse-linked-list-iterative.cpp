/**
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
      ListNode* prv = nullptr;
      ListNode* cur = head;
      while (cur != nullptr) {
        ListNode* nxt = cur->next;
        cur->next = prv;
        prv = cur;
        cur = nxt;
      }
      return prv;
    }
};
