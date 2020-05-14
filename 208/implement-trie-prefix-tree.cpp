struct Node {
  Node* children[26] = {nullptr};
  bool end = false;
};

class Trie {
  private:
    Node* root;

  public:
    // Initialize your data structure here.
    Trie() {
      root = new Node();
    }
    
    // Inserts a word into the trie.
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
    
    // Returns if the word is in the trie.
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
    
    // Returns if there is any word in the trie that starts with the given prefix.
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
