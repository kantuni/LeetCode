class Solution {
  private:
    map<int, map<int, int>> memo;

    bool remember(string& s, int i, int j) {
      if (memo.count(i) == 0 or memo[i].count(j) == 0) {
        memo[i][j] = solve(s, i, j);
      }
      return memo[i][j];
    }

    bool solve(string& s, int i, int j) {
      if (i > j) {
        return true;
      }
      if (i == s.size() or j == -1) {
        return false;
      }
      return s[i] == s[j] and remember(s, i + 1, j - 1);
    }

  public:
    int countSubstrings(string s) {
      int ans = 0;
      for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
          ans += solve(s, i, j);
        }
      }
      return ans;
    }
};
