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
      stack<ListNode*> s;
      while (head != nullptr) {
        int value = head->val;
        s.push(new ListNode(value));
        head = head->next;
      }
      ListNode* tmp = new ListNode(-1);
      head = tmp;
      while (!s.empty()) {
        tmp->next = s.top(); s.pop();
        tmp = tmp->next;
      }
      return head->next;
    }
};
