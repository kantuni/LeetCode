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
  public:
    int distributeCoins(TreeNode* root) {
      auto [_, cost] = helper(root);
      return cost;
    }

    pair<int, int> helper(TreeNode* root) {
      if (root == nullptr) {
        return {0, 0};
      }
      if (root->left and root->right) {
        auto [vl, cl] = helper(root->left);
        auto [vr, cr] = helper(root->right);
        int nv = root->val + (vl - 1) + (vr - 1);
        return {nv, cl + cr + abs(vl - 1) + abs(vr - 1)};
      }
      if (root->left) {
        auto [vl, cl] = helper(root->left);
        int nv = root->val + (vl - 1);
        return {nv, cl + abs(vl - 1)};
      }
      if (root->right) {
        auto [vr, cr] = helper(root->right);
        int nv = root->val + (vr - 1);
        return {nv, cr + abs(vr - 1)};
      }
      return {root->val, 0};
    }
};
