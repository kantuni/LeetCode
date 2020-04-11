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
    int diameter = 0;

    int maxHeight(TreeNode* root) {
      if (root == nullptr) {
        return 0;
      }
      auto l = maxHeight(root->left);
      auto r = maxHeight(root->right);
      diameter = max(diameter, l + r);
      return 1 + max(l, r);
    }

  public:
    int diameterOfBinaryTree(TreeNode* root) {
      maxHeight(root);
      return diameter;
    }
};
