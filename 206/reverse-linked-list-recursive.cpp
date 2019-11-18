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
      if (head == nullptr) {
        return nullptr;
      }
      if (head->next == nullptr) {
        return head;
      }
      ListNode* newHead = reverseList(head->next);
      ListNode* tmp = newHead;
      while (tmp->next != nullptr) {
        tmp = tmp->next;
      }
      tmp->next = new ListNode(head->val);
      return newHead;
    }
};
