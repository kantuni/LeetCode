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
    vector<double> averageOfLevels(TreeNode* root) {
      map<int, vector<long long>> memo;
      queue<pair<TreeNode*, int>> q;
      q.push({root, 0});
      while (!q.empty()) {
        auto [node, level] = q.front(); q.pop();
        memo[level].push_back((long long) node->val);
        if (node->left != nullptr) {
          q.push({node->left, level + 1});
        }
        if (node->right != nullptr) {
          q.push({node->right, level + 1});
        }
      }
      vector<double> ans;
      for (auto [_, nodes]: memo) {
        long long sum = accumulate(nodes.begin(), nodes.end(), 0LL);
        ans.push_back(1.0 * sum / nodes.size());
      }
      return ans;
    }
};
