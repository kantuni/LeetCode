class Solution {
  private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};

    void dfs(vector<vector<char>>& grid, int r, int c) {
      grid[r][c] = '2';
      for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        bool rok = 0 <= nr and nr < grid.size();
        bool cok = 0 <= nc and nc < grid[0].size();
        if (rok and cok and grid[nr][nc] == '1') {
          dfs(grid, nr, nc);
        }
      }
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
