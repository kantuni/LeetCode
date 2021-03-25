class Solution {
  public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
      if (matrix.size() == 0) {
        return {};
      }
      vector<int> dr = {-1, 0, 0, 1};
      vector<int> dc = {0, -1, 1, 0};
      int m = matrix.size(), n = matrix[0].size();
      vector<vector<int>> pc(m, vector<int>(n));
      vector<vector<int>> ac(m, vector<int>(n));
      queue<pair<int, int>> pq, aq;
      for (int r = 0; r < m; r++) {
        pq.push({r, 0});
        pc[r][0] = 1;
        aq.push({r, n - 1});
        ac[r][n - 1] = 1;
      }
      for (int c = 0; c < n; c++) {
        pq.push({0, c});
        pc[0][c] = 1;
        aq.push({m - 1, c});
        ac[m - 1][c] = 1;
      }
      while (!pq.empty()) {
        auto [r, c] = pq.front(); pq.pop();
        for (int i = 0; i < 4; i++) {
          int nr = r + dr[i], nc = c + dc[i];
          if (nr == -1 or nr == m or nc == -1 or nc == n) {
            continue;
          }
          if (pc[nr][nc] == 0 and matrix[nr][nc] >= matrix[r][c]) {
            pq.push({nr, nc});
            pc[nr][nc] = 1;
          }
        }
      }
      while (!aq.empty()) {
        auto [r, c] = aq.front(); aq.pop();
        for (int i = 0; i < 4; i++) {
          int nr = r + dr[i], nc = c + dc[i];
          if (nr == -1 or nr == m or nc == -1 or nc == n) {
            continue;
          }
          if (ac[nr][nc] == 0 and matrix[nr][nc] >= matrix[r][c]) {
            aq.push({nr, nc});
            ac[nr][nc] = 1;
          }
        }
      }
      vector<vector<int>> ans;
      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
          if (pc[r][c] == 1 and ac[r][c] == 1) {
            ans.push_back({r, c});
          }
        }
      }
      return ans;
    }
};
