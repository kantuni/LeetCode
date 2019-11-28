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
      ListNode* tmp = head;
      int len = 0;
      while (tmp != nullptr) {
        tmp = tmp->next;
        len++;
      }
      return len;
    }
  
    ListNode* reverseHalf(ListNode* head, int n) {
      ListNode* prv = nullptr;
      for (int i = 0; i < n / 2; i++) {
        ListNode* tmp = head->next;
        head->next = prv;
        prv = head;
        head = tmp;
      }
      return prv;
    }

  public:
    bool isPalindrome(ListNode* head) {
      int len = getLength(head);
      ListNode* ltor = head;
      for (int i = 0; i < len / 2 + len % 2; i++) {
        ltor = ltor->next;
      }
      ListNode* rtol = reverseHalf(head, len);
      while (ltor and rtol and ltor->val == rtol->val) {
        ltor = ltor->next;
        rtol = rtol->next;
      }
      return ltor == rtol;
    }
};
