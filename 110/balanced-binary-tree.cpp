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
    int solve(TreeNode* root) {
      if (root == nullptr) {
        return 0;
      }
      int lh = solve(root->left);
      int rh = solve(root->right);
      if (lh == -1 or rh == -1 or abs(lh - rh) > 1) {
        // -1 for unbalanced
        return -1;
      }
      return 1 + max(lh, rh);
    }

  public:
    bool isBalanced(TreeNode* root) {
      if (root == nullptr) {
        return true;
      }
      return solve(root) != -1;
    }
};
