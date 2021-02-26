class Solution {
  private:
    set<string> words;
    map<string, bool> memo;
  
    bool remember(string s) {
      if (memo.count(s) == 0) {
        memo[s] = solve(s);
      }
      return memo[s];
    }

    bool solve(string s) {
      if (s.size() == 0) {
        return true;
      }
      bool ok = false;
      for (int i = 0; i < s.size(); i++) {
        string px = s.substr(0, i + 1);
        string sx = s.substr(i + 1);
        if (words.count(px) > 0 and remember(sx)) {
          ok = true;
        }
      }
      return ok;
    }

  public:
    bool wordBreak(string s, vector<string>& wordDict) {
      for (auto word: wordDict) {
        words.insert(word);
      }
      return solve(s);
    }
};
