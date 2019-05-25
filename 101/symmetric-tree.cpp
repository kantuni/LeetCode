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
  private:
    bool traverse(TreeNode *p, TreeNode *q) {
      if (p == nullptr and q == nullptr) {
        return true;
      }
      if (p != nullptr and q != nullptr and p->val == q->val) {
        return traverse(p->left, q->right) and traverse(p->right, q->left);
      }
      return false;
    }

  public:
    bool isSymmetric(TreeNode* root) {
      return traverse(root, root);
    }
};
