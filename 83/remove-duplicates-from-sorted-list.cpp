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
    ListNode* deleteDuplicates(ListNode* head) {
      if (head == nullptr) {
        return head;
      }
      ListNode *cur = head, *nxt = head->next;
      while (nxt != nullptr) {
        if (cur->val == nxt->val) {
          cur->next = nxt->next;
        } else {
          cur = nxt;
        }
        nxt = nxt->next;
      }
      return head;
    }
};
