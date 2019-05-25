/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
  public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if (p == nullptr and q == nullptr) {
        return true;
      }
      if (p != nullptr and q != nullptr and p->val == q->val) {
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
      }
      return false;
    }
};
