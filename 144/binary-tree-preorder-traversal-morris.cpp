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
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> ans;
      auto cur = root;
      while (cur != nullptr) {
        ans.push_back(cur->val);
        if (cur->left == nullptr) {
          cur = cur->right;
        } else {
          auto pred = cur->left;
          while (pred->right != nullptr) {
            pred = pred->right;
          }
          pred->right = cur->right;
          cur->right = nullptr;
          cur = cur->left;
        }
      }
      return ans;
    }
};
