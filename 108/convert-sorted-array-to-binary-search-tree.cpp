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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      int n = nums.size();
      if (n == 0) {
        return nullptr;
      }
      TreeNode* root = new TreeNode(nums[n / 2]);
      vector<int> lTree(nums.begin(), nums.begin() + n / 2);
      vector<int> rTree(nums.begin() + n / 2 + 1, nums.end());
      root->left = sortedArrayToBST(lTree);
      root->right = sortedArrayToBST(rTree);
      return root;
    }
};
