class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      if (matrix.size() == 0) {
        return {};
      }
      int n = matrix.size(), m = matrix.front().size();
      vector<vector<int>> color(n, vector<int>(m));
      vector<int> ans;
      int i = 0, j = 0;
      while (ans.size() < n * m - 1) {
        // right
        while (j + 1 < m and color[i][j + 1] == 0) {
          ans.push_back(matrix[i][j]);
          color[i][j] = 1;
          j++;
        }
        // down
        while (i + 1 < n and color[i + 1][j] == 0) {
          ans.push_back(matrix[i][j]);
          color[i][j] = 1;
          i++;
        }
        // left
        while (j - 1 >= 0 and color[i][j - 1] == 0) {
          ans.push_back(matrix[i][j]);
          color[i][j] = 1;
          j--;
        }
        // up
        while (i - 1 >= 0 and color[i - 1][j] == 0) {
          ans.push_back(matrix[i][j]);
          color[i][j] = 1;
          i--;
        }
      }
      ans.push_back(matrix[i][j]);
      return ans;
    }
};
