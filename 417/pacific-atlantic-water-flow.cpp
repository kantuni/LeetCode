class Solution {
  private:
    int m, n;
    vector<vector<int>> color;
    vector<int> dr = {-1, 0, 0, 1};
    vector<int> dc = {0, -1, 1, 0};

    void dfs(vector<vector<int>>& g, int r, int c) {
      color[r][c] = 1;
      for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr < 0 or nc < 0 or nr == m or nc == n) {
          continue;
        }
        if (color[nr][nc] == 0 and g[r][c] >= g[nr][nc]) {
          dfs(g, nr, nc);
        }
      }
    }

  public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
      if (matrix.size() == 0) {
        return {};
      }
      m = matrix.size(), n = matrix[0].size();
      vector<vector<int>> ans;
      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
          color.assign(m, vector<int>(n, 0));
          dfs(matrix, r, c);
          bool pacific = false;
          for (int i = 0; i < m; i++) {
            if (color[i][0] == 1) {
              pacific = true;
              break;
            }
          }
          for (int i = 0; i < n; i++) {
            if (color[0][i] == 1) {
              pacific = true;
              break;
            }
          }
          bool atlantic = false;
          for (int i = 0; i < m; i++) {
            if (color[i][n - 1] == 1) {
              atlantic = true;
              break;
            }
          }
          for (int i = 0; i < n; i++) {
            if (color[m - 1][i] == 1) {
              atlantic = true;
              break;
            }
          }
          if (pacific and atlantic) {
            ans.push_back({r, c});
          }
        }
      }
      return ans;
    }
};
