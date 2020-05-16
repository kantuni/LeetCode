/**
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
  public:
    ListNode* oddEvenList(ListNode* head) {
      if (head == nullptr) {
        return nullptr;
      }
      ListNode *odd = head, *even = head->next;
      while (head and head->next) {
        auto o = head, e = head->next;
        o->next = (o->next) ? o->next->next : nullptr;
        e->next = (e->next) ? e->next->next : nullptr;
        head = head->next;
      }
      auto tmp = odd;
      while (tmp->next) {
        tmp = tmp->next;
      }
      tmp->next = even;
      return odd;
    }
};
