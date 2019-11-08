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
    ListNode* removeElements(ListNode* head, int val) {
      if (head == nullptr) {
        return nullptr;
      }
      if (head->val == val) {
        return removeElements(head->next, val);
      }
      head->next = removeElements(head->next, val);
      return head;
    }
};
