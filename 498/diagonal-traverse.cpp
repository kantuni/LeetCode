// WA
class Solution {
  public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
      if (matrix.size() == 0) return {};
      int m = matrix.size(), n = matrix[0].size();
      vector<vector<int>> color(m, vector<int>(n));
      vector<int> upper;
      for (int i = 0; i < min(m, n); i++) {
        for (int j = 0; j < min(m, n) and i - j > -1; j++) {
          if (i % 2 == 0) {
            if (color[i - j][j] == 0) {
              upper.push_back(matrix[i - j][j]);
            }
            color[i - j][j] = 1;
          } else {
            if (color[j][i - j] == 0) {
              upper.push_back(matrix[j][i - j]);
            }
            color[j][i - j] = 1;
          }
        }
      }
      vector<int> lower;
      for (int i = 0; i < min(m, n); i++) {
        for (int j = 0; j < min(m, n) and i - j > -1; j++) {
          if ((min(m, n) - i) % 2 == 1) {
            if (color[m - 1 - i + j][n - 1 - j] == 0) {
              lower.push_back(matrix[m - 1 - i + j][n - 1 - j]);
            }
            color[m - 1 - i + j][n - 1 - j] = 1;
          } else {
            if (color[m - 1 - j][n - 1 - i + j] == 0) {
              lower.push_back(matrix[m - 1 - j][n - 1 - i + j]);
            }
            color[m - 1 - j][n - 1 - i + j] = 1;
          }
        }
      }
      reverse(lower.begin(), lower.end());
      vector<int> ans(upper);
      ans.insert(ans.end(), lower.begin(), lower.end());
      return ans;
    }
};
