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
      auto root = new TreeNode();
      root->val = order[start];
      int mid = end;
      for (int i = start; i < end; i++) {
        if (order[i] > order[start]) {
          mid = i;
          break;
        }
      }
      root->left = helper(order, start + 1, mid);
      root->right = helper(order, mid, end);
      return root;
    }

  public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      return helper(preorder, 0, preorder.size());
    }
};
