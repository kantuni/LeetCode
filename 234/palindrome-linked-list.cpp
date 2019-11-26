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
    ListNode* copy(ListNode* head) {
      ListNode* newHead = new ListNode(-1);
      ListNode* tmp = newHead;
      while (head != nullptr) {
        tmp->next = new ListNode(head->val);
        tmp = tmp->next;
        head = head->next;
      }
      return newHead->next;
    }

    ListNode* reverseList(ListNode* head) {
      ListNode* prv = nullptr;
      while (head != nullptr) {
        ListNode* tmp = head->next;
        head->next = prv;
        prv = head;
        head = tmp;
      }
      return prv;
    }

  public:
    bool isPalindrome(ListNode* head) {
      ListNode* tmp = copy(head);
      ListNode* tail = reverseList(tmp);
      while (head and tail and head->val == tail->val) {
        head = head->next;
        tail = tail->next;
      }
      return head == tail;
    }
};
