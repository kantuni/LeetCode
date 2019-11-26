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
      if (head == nullptr) {
        return nullptr;
      }
      if (head->next == nullptr) {
        return head;
      }
      ListNode* newHead = reverseList(head->next);
      head->next->next = head;
      head->next = nullptr;
      return newHead;
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
