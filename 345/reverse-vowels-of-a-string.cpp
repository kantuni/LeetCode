class Solution {
  private:
    bool isVowel(char c) {
      return (
        c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or
        c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U'
      );
    }

  public:
    string reverseVowels(string s) {
      vector<int> pos;
      for (int i = 0; i < s.size(); i++) {
        if (isVowel(s[i])) {
          pos.push_back(i);
        }
      }
      for (int i = 0; i < pos.size() / 2; i++) {
        swap(s[pos[i]], s[pos[pos.size() - 1 - i]]);
      }
      return s;
    }
};
