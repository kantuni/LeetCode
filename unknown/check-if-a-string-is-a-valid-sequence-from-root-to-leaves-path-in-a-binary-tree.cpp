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
    bool helper(TreeNode* root, vector<int>& a, int index) {
      if (root == nullptr) {
        return false;
      }
      if (root->left == nullptr and root->right == nullptr) {
        return index == a.size() - 1 and root->val == a[index];
      }
      if (index >= a.size() or root->val != a[index]) {
        return false;
      }
      auto left = helper(root->left, a, index + 1);
      auto right = helper(root->right, a, index + 1);
      return left or right;
    }

  public:
    bool isValidSequence(TreeNode* root, vector<int>& a) {
      return helper(root, a, 0);
    }
};
