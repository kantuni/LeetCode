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
    int pos = 0;
    vector<int> ans;

    bool preorder(TreeNode* root, vector<int>& voyage) {
      if (root == nullptr) {
        return true;
      }
      if (root->val != voyage[pos]) {
        return false;
      }
      pos++;
      if (root->left and root->left->val != voyage[pos]) {
        swap(root->left, root->right);
        ans.push_back(root->val);
      }
      return preorder(root->left, voyage) and preorder(root->right, voyage);
    }

  public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
      return preorder(root, voyage) ? ans : vector<int>{-1};
    }
};
