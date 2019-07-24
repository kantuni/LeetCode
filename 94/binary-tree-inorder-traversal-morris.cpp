// Morris Traversal
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
      vector<int> ans;
      auto cur = root;
      while (cur != nullptr) {
        if (cur->left != nullptr) {
          auto pred = cur->left;
          while (pred->right != nullptr) {
            pred = pred->right;
          }
          auto tmp = cur;
          cur = cur->left;
          tmp->left = nullptr;
          pred->right = tmp;
        } else {
          ans.push_back(cur->val);
          cur = cur->right;
        }
      }
      return ans;
    }
};
