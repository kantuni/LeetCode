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
    TreeNode* solve(vector<int>& in, int is, int ie, vector<int>& post, int ps, int pe) {
      if (is >= ie or ps >= pe) {
        return nullptr;
      }
      auto val = post[pe - 1];
      auto root = new TreeNode(val);
      auto index = find(in.begin() + is, in.begin() + ie, val) - in.begin();
      root->left = solve(in, is, index, post, ps, ps + index - is);
      root->right = solve(in, index + 1, ie, post, ps + index - is, pe - 1);
      return root;
    }

  public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      return solve(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
