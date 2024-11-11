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
  public:
    int distributeCoins(TreeNode* root) {
      vector<int> costs;
      helper(root, costs);
      return accumulate(costs.begin(), costs.end(), 0);
    }

    int helper(TreeNode* root, vector<int>& costs) {
      if (root == nullptr) {
        return 0;
      }
      if (root->left and root->right) {
        int vl = helper(root->left, costs);
        int vr = helper(root->right, costs);
        costs.push_back(abs(vl - 1));
        costs.push_back(abs(vr - 1));
        int nv = root->val + (vl - 1) + (vr - 1);
        root->val = nv;
        return nv;
      }
      if (root->left) {
        int vl = helper(root->left, costs);
        costs.push_back(abs(vl - 1));
        int nv = root->val + (vl - 1);
        root->val = nv;
        return nv;
      }
      if (root->right) {
        int vr = helper(root->right, costs);
        costs.push_back(abs(vr - 1));
        int nv = root->val + (vr - 1);
        root->val = nv;
        return nv;
      }
      int nv = root->val;
      root->val = 1;
      return nv;
    }
};
