class Solution {
  public:
    int islandPerimeter(vector<vector<int>>& grid) {
      int ans = 0;
      for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[r].size(); c++) {
          bool L = c > 0 ? grid[r][c - 1] : false;
          bool R = c + 1 < grid[r].size() ? grid[r][c + 1] : false;
          bool U = r > 0 ? grid[r - 1][c] : false;
          bool D = r + 1 < grid.size() ? grid[r + 1][c] : false;
          if (grid[r][c] == 1) {
            ans += !L + !R + !U + !D;
          }
        }
      }
      return ans;
    }
};
