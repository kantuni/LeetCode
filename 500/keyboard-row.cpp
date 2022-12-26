class Solution {
  private:
    bool withOneRow(string word, string row) {
      set<char> memo;
      for (auto letter: row) {
        memo.insert(letter);
      }
      for (auto letter: word) {
        if (memo.count(tolower(letter)) == 0) {
          return false;
        }
      }
      return true;
    }

  public:
    vector<string> findWords(vector<string>& words) {
      string r1 = "qwertyuiop";
      string r2 = "asdfghjkl";
      string r3 = "zxcvbnm";
      vector<string> ans;
      for (auto w: words) {
        if (withOneRow(w, r1) or withOneRow(w, r2) or withOneRow(w, r3)) {
          ans.push_back(w);
        }
      }
      return ans;
    }
};
