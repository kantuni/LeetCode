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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      if (inorder.empty() and postorder.empty()) {
        return nullptr;
      }
      auto val = postorder.back();
      auto root = new TreeNode(val);
      auto it = find(inorder.begin(), inorder.end(), val);
      vector<int> lin(inorder.begin(), it);
      vector<int> rin(it + 1, inorder.end());
      vector<int> lpost(postorder.begin(), postorder.begin() + lin.size());
      vector<int> rpost(postorder.begin() + lin.size(), postorder.end() - 1);
      root->left = buildTree(lin, lpost);
      root->right = buildTree(rin, rpost);
      return root;
    }
};
