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
    const int INF = 1e9;
    map<TreeNode*, pair<int, int>> memo;
    int ans = -INF;
  
    pair<int, int> helper(TreeNode* root) {
      if (root == nullptr) {
        return {-INF, 0};
      }
      auto left = root->left, right = root->right;
      if (memo.count(left) == 0) {
        memo[left] = helper(left);
      }
      if (memo.count(right) == 0) {
        memo[right] = helper(right);
      }
      auto [lin, lout] = memo[left];
      auto [rin, rout] = memo[right];
      pair<int, int> tmp = {
        max({lin, rin, max(lout + rout, 0) + root->val}),
        root->val + max({lout, rout, 0})
      };
      ans = max({ans, tmp.first, tmp.second});
      return tmp;
    }
  
  public:
    int maxPathSum(TreeNode* root) {
      helper(root);
      return ans;
    }
};
