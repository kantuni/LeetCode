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
    TreeNode* invertTree(TreeNode* root) {
      if (root == nullptr) {
        return nullptr;
      }
      queue<TreeNode*> q;
      q.push(root);
      while (!q.empty()) {
        auto front = q.front(); q.pop();
        swap(front->left, front->right);
        if (front->left != nullptr) {
          q.push(front->left);
        }
        if (front->right != nullptr) {
          q.push(front->right);
        }
      }
      return root;
    }
};
