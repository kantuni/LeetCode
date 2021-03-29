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
    void preorder(TreeNode* root, queue<int>& q, vector<int>& ans) {
      if (root == nullptr) {
        return;
      }
      if (root->val != q.front()) {
        ans.push_back(-1);
      }
      q.pop();
      if (root->left != nullptr and root->left->val != q.front()) {
        swap(root->left, root->right);
        ans.push_back(root->val);
      }
      preorder(root->left, q, ans);
      preorder(root->right, q, ans);
    }

  public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
      queue<int> q;
      for (auto value: voyage) {
        q.push(value);
      }
      vector<int> ans;
      preorder(root, q, ans);
      int cnt = count(ans.begin(), ans.end(), -1);
      if (cnt > 0) {
        return {-1};
      }
      return ans;
    }
};
