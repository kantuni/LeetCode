/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  private:
    void preorder(TreeNode* root, vector<int>& voyage, vector<int>& ans) {
      if (root == nullptr) {
        return;
      }
      if (root->val != voyage.back()) {
        ans.push_back(-1);
      }
      voyage.pop_back();
      if (root->left != nullptr and root->left->val != voyage.back()) {
        swap(root->left, root->right);
        ans.push_back(root->val);
      }
      preorder(root->left, voyage, ans);
      preorder(root->right, voyage, ans);
    }

  public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
      reverse(voyage.begin(), voyage.end());
      vector<int> ans;
      preorder(root, voyage, ans);
      int cnt = count(ans.begin(), ans.end(), -1);
      if (cnt > 0) {
        return {-1};
      }
      return ans;
    }
};
