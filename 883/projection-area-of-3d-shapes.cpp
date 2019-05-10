class Solution {
  public:
    int projectionArea(vector<vector<int>>& grid) {
      int s1 = 0, s2 = 0, s3 = 0;
      for (int i = 0; i < grid.size(); i++) {
        int m1 = 0, m2 = 0;
        for (int j = 0; j < grid[i].size(); j++) {
          if (grid[i][j] > 0) {
            s1++;
          }
          m1 = max(m1, grid[i][j]);
          m2 = max(m2, grid[j][i]);
        }
        s2 += m1;
        s3 += m2;
      }
      return s1 + s2 + s3;
    }
};
