class Solution {
  private:
    map<int, set<string>> lw;
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
      for (auto [len, words]: lw) {
        if (len <= s.size()) {
          string px = s.substr(0, len);
          string sx = s.substr(len);
          if (words.count(px) > 0 and remember(sx)) {
            return true;
          }
        }
      }
      return false;
    }

  public:
    bool wordBreak(string s, vector<string>& wordDict) {
      for (auto word: wordDict) {
        lw[word.size()].insert(word);
      }
      return solve(s);
    }
};
