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
    vector<vector<int>> levelOrder(TreeNode* root) {
      if (root == nullptr) {
        return {};
      }
      vector<vector<int>> ans;
      queue<TreeNode*> q;
      q.push(root);
      while (!q.empty()) {
        vector<int> lvl;
        int cnt = q.size();
        while (cnt--) {
          auto cur = q.front(); q.pop();
          lvl.push_back(cur->val);
          if (cur->left != nullptr) {
            q.push(cur->left);
          }
          if (cur->right != nullptr) {
            q.push(cur->right);
          }
        }
        ans.push_back(lvl);
      }
      return ans;
    }
};
