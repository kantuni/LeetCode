/*
// Definition for a Node.
class Node {
  public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
      val = _val;
      left = _left;
      right = _right;
      next = _next;
    }
};
*/

class Solution {
  public:
    Node* connect(Node* root) {
      if (root == nullptr) {
        return nullptr;
      }
      // attach the rightmost node in the left subtree
      // to the leftmost node in the right subtree
      auto rmost = root->left;
      auto lmost = root->right;
      while (rmost != nullptr and lmost != nullptr) {
        rmost->next = lmost;
        rmost = rmost->right;
        lmost = lmost->left;
      }
      root->left = connect(root->left);
      root->right = connect(root->right);
      return root;
    }
};
