class Solution {
  public:
    int minPathSum(vector<vector<int>>& grid) {
      if (grid.size() == 0) {
        return 0;
      }
      int n = grid.size();
      int m = grid[0].size();
      int cost[n][m];
      for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
          if (r == 0 and c == 0) {
            cost[r][c] = grid[r][c];
          } else if (r == 0 and c > 0) {
            cost[r][c] = grid[r][c] + cost[r][c - 1];
          } else if (r > 0 and c == 0) {
            cost[r][c] = grid[r][c] + cost[r - 1][c];
          } else {
            cost[r][c] = (
              grid[r][c] +
              min(cost[r - 1][c], cost[r][c - 1])
            );
          }
        }
      }
      return cost[n - 1][m - 1];
    }
};
