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
      map<TreeNode*, bool> memo;
      stack<TreeNode*> s;
      s.push(root);
      while (!s.empty()) {
        auto cur = s.top();
        if (memo[cur]) {
          ans.push_back(cur->val);
          s.pop();
        } else {
          if (cur->right != nullptr) {
            s.push(cur->right);
          }
          if (cur->left != nullptr) {
            s.push(cur->left);
          }
          memo[cur] = true;
        }
      }
      return ans;
    }
};
