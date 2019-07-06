class Solution {
  public:
    bool detectCapitalUse(string word) {
      bool c1 = true;
      for (auto letter: word) {
        if (islower(letter)) {
          c1 = false;
          break;
        }
      }
      bool c2 = true;
      for (auto letter: word) {
        if (isupper(letter)) {
          c2 = false;
          break;
        }
      }
      bool c3 = isupper(word[0]);
      for (int i = 1; i < word.size(); i++) {
        if (isupper(word[i])) {
          c3 = false;
          break;
        }
      }
      return c1 or c2 or c3;
    }
};
