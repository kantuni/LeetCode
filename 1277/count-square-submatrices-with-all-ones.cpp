class Solution {
  public:
    int countSquares(vector<vector<int>>& matrix) {
      int n = matrix.size(), m = matrix[0].size();
      int memo[n + 1][m + 1];
      memset(memo, 0, sizeof memo);
      int ans = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (matrix[i - 1][j - 1] == 1) {
            memo[i][j] = 1 + min({
              memo[i - 1][j],
              memo[i][j - 1],
              memo[i - 1][j - 1]
            });
            ans += memo[i][j];
          }
        }
      }
      return ans;
    }
};
