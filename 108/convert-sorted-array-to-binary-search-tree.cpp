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
    TreeNode* solve(vector<int>& nums, int start, int end) {
      int n = end - start + 1;
      if (n == 0 or start > end) {
        return nullptr;
      }
      TreeNode* root = new TreeNode(nums[start + n / 2]);
      root->left = solve(nums, start, start + n / 2 - 1);
      root->right = solve(nums, start + n / 2 + 1, end);
      return root;
    }

  public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return solve(nums, 0, nums.size() - 1);
    }
};
