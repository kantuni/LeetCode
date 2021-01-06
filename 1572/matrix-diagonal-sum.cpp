class Solution {
  public:
    int diagonalSum(vector<vector<int>>& mat) {
      int n = mat.size();
      int ans = 0;
      for (int i = 0; i < n; i++) {
        ans += mat[i][i];
      }
      for (int i = n - 1; i > -1; i--) {
        ans += mat[n - 1 - i][i];
      }
      if (n % 2 == 1) {
        ans -= mat[n - 1 - n / 2][n - 1 - n / 2];
      }
      return ans;
    }
};
