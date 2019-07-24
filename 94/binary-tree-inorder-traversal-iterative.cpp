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
    vector<int> inorderTraversal(TreeNode* root) {
      if (root == nullptr) {
        return {};
      }
      vector<int> ans;
      stack<TreeNode*> s;
      auto cur = root;
      while (cur != nullptr || !s.empty()) {
        while (cur != nullptr) {
          s.push(cur);
          cur = cur->left;
        }
        cur = s.top(); s.pop();
        ans.push_back(cur->val);
        cur = cur->right;
      }
      return ans;
    }
};
