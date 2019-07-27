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
    TreeNode* solve(vector<int>& pre, int ps, int pe, vector<int>& in, int is, int ie) {
      if (ps >= pe or is >= ie) {
        return nullptr;
      }
      auto val = pre[ps];
      auto root = new TreeNode(val);
      auto index = find(in.begin() + is, in.begin() + ie, val) - in.begin();
      root->left = solve(pre, ps + 1, ps + 1 + index - is, in, is, index);
      root->right = solve(pre, ps + 1 + index - is, pe, in, index + 1, ie);
      return root;
    }

  public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      return solve(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
