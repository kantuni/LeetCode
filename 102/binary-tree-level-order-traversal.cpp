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
    int countLevels(TreeNode* root) {
      if (root == nullptr) {
        return 0;
      }
      return 1 + max(countLevels(root->left), countLevels(root->right));
    }

  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      if (root == nullptr) {
        return {};
      }
      int lvls = countLevels(root);
      vector<vector<int>> ans(lvls);
      ans[0].push_back(root->val);
      queue<pair<TreeNode*, int>> q;
      q.push({root, 0});
      while (!q.empty()) {
        auto [cur, lvl] = q.front(); q.pop();
        if (cur->left != nullptr) {
          q.push({cur->left, lvl + 1});
          ans[lvl + 1].push_back(cur->left->val);
        }
        if (cur->right != nullptr) {
          q.push({cur->right, lvl + 1});
          ans[lvl + 1].push_back(cur->right->val);
        }
      }
      return ans;
    }
};
