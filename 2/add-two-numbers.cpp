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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* ans = new ListNode(-1);
      ListNode* tail = ans;
      int carry = 0;
      while (l1 != nullptr and l2 != nullptr) {
        int value = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        tail->next = new ListNode(value);
        tail = tail->next;
        l1 = l1->next;
        l2 = l2->next;
      }
      while (l1 != nullptr) {
        int value = (l1->val + carry) % 10;
        carry = (l1->val + carry) / 10;
        tail->next = new ListNode(value);
        tail = tail->next;
        l1 = l1->next;
      }
      while (l2 != nullptr) {
        int value = (l2->val + carry) % 10;
        carry = (l2->val + carry) / 10;
        tail->next = new ListNode(value);
        tail = tail->next;
        l2 = l2->next;
      }
      if (carry > 0) {
        tail->next = new ListNode(carry);
      }
      ans = ans->next;
      return ans;
    }
};
