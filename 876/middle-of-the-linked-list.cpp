/**
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution {
  public:
    ListNode* middleNode(ListNode* head) {
      ListNode* tmp = head;
      int n = 0;
      while (tmp != nullptr) {
        tmp = tmp->next;
        n++;
      }
      for (int i = 0; i < n / 2; i++) {
        head = head->next;
      }
      return head;
    }
};
