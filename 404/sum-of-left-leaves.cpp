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
    bool isLeaf(TreeNode* node) {
      return (
        node != nullptr and 
        node->left == nullptr and 
        node->right == nullptr
      );
    }

  public:
    int sumOfLeftLeaves(TreeNode* root) {
      if (root == nullptr) {
        return 0;
      }
      int left = isLeaf(root->left) 
        ? root->left->val
        : sumOfLeftLeaves(root->left);
      int right = sumOfLeftLeaves(root->right);
      return left + right;
    }
};
