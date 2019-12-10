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
    vector<TreeNode*> dfs(TreeNode* root, TreeNode* node) {
      set<TreeNode*> memo;
      stack<TreeNode*> s;
      memo.insert(root);
      s.push(root);
      while (s.top() != node) {
        auto top = s.top();
        memo.insert(top);
        if (top->left and memo.count(top->left) == 0) {
          s.push(top->left);
          continue;
        }
        if (top->right and memo.count(top->right) == 0) {
          s.push(top->right);
          continue;
        }
        s.pop();
      }
      vector<TreeNode*> path;
      while (!s.empty()) {
        auto top = s.top(); s.pop();
        path.push_back(top);
      }
      reverse(path.begin(), path.end());
      return path;
    }

  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      vector<TreeNode*> pathToP = dfs(root, p);
      vector<TreeNode*> pathToQ = dfs(root, q);
      int depth = min(pathToP.size(), pathToQ.size());
      TreeNode* ans = nullptr;
      for (int i = 0; i < depth; i++) {
        if (pathToP[i] != pathToQ[i]) {
          break;          
        }
        ans = pathToP[i];
      }
      return ans;
    }
};
