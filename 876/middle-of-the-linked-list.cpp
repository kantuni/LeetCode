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
    ListNode* middleNode(ListNode* head) {
      ListNode *slow = head, *fast = head;
      while (fast != nullptr and fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
      }
      return slow;
    }
};
