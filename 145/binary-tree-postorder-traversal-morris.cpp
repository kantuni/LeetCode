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
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> ans;
      auto cur = root;
      // symmetrically opposite to Morris preorder traversal
      while (cur != nullptr) {
        ans.push_back(cur->val);
        if (cur->right == nullptr) {
          cur = cur->left;
        } else {
          auto pred = cur->right;
          while (pred->left != nullptr) {
            pred = pred->left;
          }
          pred->left = cur->left;
          cur->left = nullptr;
          cur = cur->right;
        }
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};
