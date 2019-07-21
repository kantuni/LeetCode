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
      if (root == nullptr) {
        return {};
      }
      vector<int> ans;
      stack<TreeNode*> s;
      s.push(root);
      while (!s.empty()) {
        auto top = s.top();
        s.pop();
        ans.push_back(top->val);
        if (top->right != nullptr) {
          s.push(top->right);
        }
        if (top->left != nullptr) {
          s.push(top->left);
        }
      }
      return ans;
    }
};
