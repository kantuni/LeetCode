class Solution {
  public:
    int longestCommonSubsequence(string s, string t) {
      int n = s.size(), m = t.size();
      int memo[n + 1][m + 1];
      memset(memo, 0, sizeof memo);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (s[i] == t[j]) {
            memo[i + 1][j + 1] = memo[i][j] + 1;
          } else {
            memo[i + 1][j + 1] = max(memo[i][j + 1], memo[i + 1][j]);
          }
        }
      }
      return memo[n][m];
    }
};
