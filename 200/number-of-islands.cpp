class Solution {
  private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
      bool rout = r < 0 or r >= grid.size();
      bool cout = c < 0 or c >= grid[0].size();
      if (rout or cout or grid[r][c] != '1') {
        return;
      }
      grid[r][c] = '+';
      dfs(grid, r - 1, c);
      dfs(grid, r, c - 1);
      dfs(grid, r + 1, c);
      dfs(grid, r, c + 1);
    }

  public:
    int numIslands(vector<vector<char>>& grid) {
      int ans = 0;
      for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[r].size(); c++) {
          if (grid[r][c] == '1') {
            dfs(grid, r, c);
            ans++;
          }
        }
      }
      return ans;
    }
};
