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
      int ld = minDepth(root->left);
      int rd = minDepth(root->right);
      return (ld == 0 or rd == 0) ? ld + rd + 1 : min(ld, rd) + 1;
    }
};
