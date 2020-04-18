class Solution {
  private:
    const int INF = 1e9;
    map<int, map<int, int>> memo;
  
    int remember(vector<vector<int>>& grid, int r, int c) {
      if (memo.count(r) == 0 or memo[r].count(c) == 0) {
        memo[r][c] = dfs(grid, r, c);
      }
      return memo[r][c];
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
      if (r >= grid.size() or c >= grid[0].size()) {
        return INF;
      }
      if (r == grid.size() - 1 and c == grid[0].size() - 1) {
        return grid[r][c];
      }
      int down = remember(grid, r + 1, c);
      int right = remember(grid, r, c + 1);
      return grid[r][c] + min(down, right);
    }

  public:
    int minPathSum(vector<vector<int>>& grid) {
      if (grid.size() == 0) {
        return 0;
      }
      return dfs(grid, 0, 0);
    }
};
