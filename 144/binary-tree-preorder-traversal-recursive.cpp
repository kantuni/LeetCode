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
      vector<int> left = preorderTraversal(root->left);
      vector<int> right = preorderTraversal(root->right);
      vector<int> ans;
      ans.push_back(root->val);
      ans.insert(ans.end(), left.begin(), left.end());
      ans.insert(ans.end(), right.begin(), right.end());
      return ans;
    }
};
