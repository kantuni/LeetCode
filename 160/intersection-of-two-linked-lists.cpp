/**
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
  private:
    int getLength(ListNode* head) {
      int len = 0;
      while (head != nullptr) {
        head = head->next;
        len++;
      }
      return len;
    }

  public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
      int alen = getLength(headA);
      int blen = getLength(headB);
      while (alen > 0 and blen > 0) {
        if (alen > blen) {
          headA = headA->next;
          alen--;
        } else if (alen < blen) {
          headB = headB->next;
          blen--;
        } else {
          if (headA == headB) {
            return headA;
          }
          headA = headA->next;
          headB = headB->next;
        }
      }
      return nullptr;
    }
};
