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
    TreeNode* helper(vector<int>& order, int start, int end) {
      if (start == end) {
        return nullptr;
      }
      int low = start + 1, high = end - 1;
      while (low <= high) {
        int mid = low + (high - low) / 2;
        if (order[start] > order[mid]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
      auto root = new TreeNode(order[start]);
      root->left = helper(order, start + 1, low);
      root->right = helper(order, low, end);
      return root;
    }

  public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      return helper(preorder, 0, preorder.size());
    }
};
