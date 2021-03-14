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
    ListNode* swapNodes(ListNode* head, int k) {
      map<int, ListNode*> memo;
      auto tmp = head;
      for (int i = 0; tmp != nullptr; i++) {
        memo[i] = tmp;
        tmp = tmp->next;
      }
      swap(memo[k - 1]->val, memo[memo.size() - k]->val);
      return head;
    }
};
