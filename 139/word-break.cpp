class Solution {
  private:
    map<int, set<string>> words;
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
      for (auto [len, _]: words) {
        if (len <= s.size()) {
          string px = s.substr(0, len);
          string sx = s.substr(len);
          if (words[len].count(px) > 0 and remember(sx)) {
            return true;
          }
        }
      }
      return false;
    }

  public:
    bool wordBreak(string s, vector<string>& wordDict) {
      for (auto word: wordDict) {
        words[word.size()].insert(word);
      }
      return solve(s);
    }
};
