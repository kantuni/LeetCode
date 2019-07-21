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
      map<TreeNode*, bool> memo;
      stack<TreeNode*> s;
      s.push(root);
      while (!s.empty()) {
        auto top = s.top(); s.pop();
        if (!memo.count(top)) {
          if (top->right != nullptr) {
            s.push(top->right);
          }
          s.push(top);
          if (top->left != nullptr) {
            s.push(top->left);
          }
          memo[top] = true;
        } else {
          ans.push_back(top->val);
        }
      }
      return ans;
    }
};
