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
      if (root == nullptr) {
        return {};
      }
      vector<int> ans;
      stack<TreeNode*> s;
      s.push(root);
      while (!s.empty()) {
        auto cur = s.top(); s.pop();
        ans.push_back(cur->val);
        if (cur->left != nullptr) {
          s.push(cur->left);
        }
        if (cur->right != nullptr) {
          s.push(cur->right);
        }
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};
