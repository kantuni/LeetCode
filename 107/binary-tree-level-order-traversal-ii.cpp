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
    void levelOrder(TreeNode* root, vector<vector<int>>& order, int lvl) {
      if (root == nullptr) {
        return;
      }
      if (order.size() == lvl) {
        order.push_back({});
      }
      order[lvl].push_back(root->val);
      if (root->left != nullptr) {
        levelOrder(root->left, order, lvl + 1);
      }
      if (root->right != nullptr) {
        levelOrder(root->right, order, lvl + 1);
      }
    }

  public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>> order;
      levelOrder(root, order, 0);
      reverse(order.begin(), order.end());
      return order;
    }
};
