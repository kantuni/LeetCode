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
    int minDepth(TreeNode* root) {
      if (root == nullptr) {
        return 0;
      }
      if (root->left == nullptr and root->right == nullptr) {
        return 1;
      }
      int depth = INT_MAX;
      if (root->left != nullptr) {
        int ld = minDepth(root->left);
        depth = min(depth, ld);
      }
      if (root->right != nullptr) {
        int rd = minDepth(root->right);
        depth = min(depth, rd);
      }
      return 1 + depth;
    }
};
