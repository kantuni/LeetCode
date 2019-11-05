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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
      set<ListNode*> s;
      while (headA != nullptr) {
        s.insert(headA);
        headA = headA->next;
      }
      while (headB != nullptr) {
        if (s.count(headB) > 0) {
          return headB;
        }
        headB = headB->next;
      }
      return nullptr;
    }
};
