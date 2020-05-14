struct Node {
  Node* children[26] = {nullptr};
  bool end = false;
};

class Trie {
  private:
    Node* root;

  public:
    Trie() {
      root = new Node();
    }

    void insert(string word) {
      auto current = root;
      for (auto letter: word) {
        int index = letter - 'a';
        if (current->children[index] == nullptr) {
          current->children[index] = new Node();
        }
        current = current->children[index];
      }
      current->end = true;
    }

    bool search(string word) {
      auto current = root;
      for (auto letter: word) {
        int index = letter - 'a';
        if (current->children[index] == nullptr) {
          return false;
        }
        current = current->children[index];
      }
      return current->end;
    }

    bool startsWith(string prefix) {
      auto current = root;
      for (auto letter: prefix) {
        int index = letter - 'a';
        if (current->children[index] == nullptr) {
          return false;
        }
        current = current->children[index];
      }
      return true;
    }
};
