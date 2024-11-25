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
    int countNodes(TreeNode* root) {
      TreeNode* rc = root;
      if (rc == nullptr) {
        return 0;
      }
      int th = 0;
      while (rc != nullptr) {
        rc = rc->left;
        th++;
      }
      if (th == 1) {
        return 1;
      }
      int count = 1 << (th - 1);
      int l = 0, h = count - 1;
      while (l <= h) {
        int m = l + (h - l) / 2;
        if (exists(root, binary(m, th))) {
          l = m + 1;
        } else {
          h = m - 1;
        }
      }
      return count - 1 + l;
    }

    string binary(int x, int h) {
      bitset<32> bs(x);
      string bins = bs.to_string();
      return bins.substr(bins.size() - h + 1);
    }

    bool exists(TreeNode* root, string path) {
      for (int i = 0; i < path.size(); i++) {
        if (root == nullptr) {
          return false;
        }
        if (path[i] == '0') {
          root = root->left;
        } else {
          root = root->right;
        }
      }
      return root != nullptr;
    }
};
