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
    TreeNode* invertTree(TreeNode* root) {
      if (root == nullptr) {
        return nullptr;
      }
      TreeNode* newLeft = invertTree(root->right);
      TreeNode* newRight = invertTree(root->left);
      root->left = newLeft;
      root->right = newRight;
      return root;
    }
};
