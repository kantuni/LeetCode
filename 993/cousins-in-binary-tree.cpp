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
    pair<int, int> helper(TreeNode* root, int parent, int value, int level = 0) {
      if (root == nullptr) {
        return {-1, -1};
      }
      if (root->val == value) {
        return {parent, level};
      }
      auto left = helper(root->left, root->val, value, level + 1);
      auto right = helper(root->right, root->val, value, level + 1);
      return (left.second != -1) ? left : right;
    }
  
  public:
    bool isCousins(TreeNode* root, int x, int y) {
      auto [px, lx] = helper(root, 0, x);
      auto [py, ly] = helper(root, 0, y);
      return px != py and lx == ly;
    }
};
