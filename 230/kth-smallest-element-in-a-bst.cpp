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
    vector<int> values;
  
    void inorder(TreeNode* root, int k) {
      if (root == nullptr) {
        return;
      }
      inorder(root->left, k);
      if (values.size() != k) {
        values.push_back(root->val);
      }
      inorder(root->right, k);
    }
  
  public:
    int kthSmallest(TreeNode* root, int k) {
      inorder(root, k);
      return values.back();
    }
};
