/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  private:
    int ans = INT_MIN;
  
    int helper(TreeNode* root) {
      if (root == nullptr) {
        return 0;
      }
      auto left = max(helper(root->left), 0);
      auto right = max(helper(root->right), 0);
      ans = max(ans, left + right + root->val);
      return root->val + max(left, right);
    }

  public:
    int maxPathSum(TreeNode* root) {
      helper(root);
      return ans;
    }
};
