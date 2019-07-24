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
      vector<int> left = postorderTraversal(root->left);
      vector<int> right = postorderTraversal(root->right);
      vector<int> ans;
      ans.insert(ans.end(), left.begin(), left.end());
      ans.insert(ans.end(), right.begin(), right.end());
      ans.push_back(root->val);
      return ans;
    }
};
