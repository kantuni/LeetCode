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
  private:
    vector<string> ans;
  
    void dfs(TreeNode* root, string path) {
      if (root->left == nullptr and root->right == nullptr) {
        ans.push_back(path);
      }
      if (root->left != nullptr) {
        string p = path + "->" + to_string(root->left->val);
        dfs(root->left, p);
      }
      if (root->right != nullptr) {
        string p = path + "->" + to_string(root->right->val);
        dfs(root->right, p);
      }
    }

  public:
    vector<string> binaryTreePaths(TreeNode* root) {
      if (root == nullptr) {
        return {};
      }
      string start = to_string(root->val);
      dfs(root, start);
      return ans;
    }
};
