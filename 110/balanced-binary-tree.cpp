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
    int height(TreeNode* root) {
      if (root == nullptr) {
        return 0;
      }
      int lh = height(root->left);
      int rh = height(root->right);
      return 1 + max(lh, rh);
    }

  public:
    bool isBalanced(TreeNode* root) {
      if (root == nullptr) {
        return true;
      }
      int lh = height(root->left);
      int rh = height(root->right);
      if (abs(lh - rh) > 1) {
        return false;
      }
      return isBalanced(root->left) and isBalanced(root->right);
    }
};
