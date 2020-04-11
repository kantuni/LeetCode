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
    int maxHeight(TreeNode* root) {
      if (root == nullptr) {
        return 0;
      }
      auto l = maxHeight(root->left);
      auto r = maxHeight(root->right);
      return 1 + max(l, r);
    }

  public:
    int diameterOfBinaryTree(TreeNode* root) {
      if (root == nullptr) {
        return 0;
      }
      int option1 = maxHeight(root->left) + maxHeight(root->right);
      int option2 = diameterOfBinaryTree(root->left);
      int option3 = diameterOfBinaryTree(root->right);
      return max({option1, option2, option3});
    }
};
