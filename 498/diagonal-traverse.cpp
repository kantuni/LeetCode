class Solution {
  public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
      if (matrix.size() == 0) {
        return {};
      }
      vector<int> ans;
      int n = matrix.size(), m = matrix.front().size();
      int i = 0, j = 0;
      while (ans.size() < n * m) {
        // up the diagonal
        while (0 <= i and i < n and 0 <= j and j < m) {
          ans.push_back(matrix[i][j]);
          if (i - 1 >= 0 and j + 1 < m) {
            i--, j++;
          } else {
            break;
          }
        }
        // find next start
        if (j + 1 < m) {
          j++;
        } else {
          i++;
        }
        // down the diagonal
        while (0 <= i and i < n and 0 <= j and j < m) {
          ans.push_back(matrix[i][j]);
          if (i + 1 < n and j - 1 >= 0) {
            i++, j--;
          } else {
            break;
          }
        }
        // find next start
        if (i + 1 < n) {
          i++;
        } else {
          j++;
        }
      }
      return ans;
    }
};
