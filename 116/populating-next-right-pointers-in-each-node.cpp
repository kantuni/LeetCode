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
      if (root and root->left and root->right) {
        root->left->next = root->right;
        root->right->next = root->next ? root->next->left : nullptr;
        root->left = connect(root->left);
        root->right = connect(root->right);
      }
      return root;
    }
};
