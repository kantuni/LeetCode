/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode* ans = new ListNode(-1);
      ListNode* tail = ans;
      while (l1 != nullptr and l2 != nullptr) {
        if (l1->val < l2->val) {
          tail->next = new ListNode(l1->val);
          tail = tail->next;
          l1 = l1->next;
        } else {
          tail->next = new ListNode(l2->val);
          tail = tail->next;
          l2 = l2->next;
        }
      }
      while (l1 != nullptr) {
        tail->next = new ListNode(l1->val);
        tail = tail->next;
        l1 = l1->next;
      }
      while (l2 != nullptr) {
        tail->next = new ListNode(l2->val);
        tail = tail->next;
        l2 = l2->next;
      }
      ans = ans->next;
      return ans;
    }
};
