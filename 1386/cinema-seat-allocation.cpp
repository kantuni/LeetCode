class Solution {
  public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
      map<int, vector<bool>> available;
      for (auto seat: reservedSeats) {
        int row = seat[0] - 1;
        int col = seat[1] - 1;
        if (available.count(row) == 0) {
          available[row] = vector<bool>(10, true);
        }
        available[row][col] = false;
      }
      int ans = 2 * (n - available.size());
      for (auto [row, cols]: available) {
        if (cols[1] && cols[2] && cols[3] && cols[4]) {
          cols[1] = cols[2] = cols[3] = cols[4] = false;
          ans += 1;
        }
        if (cols[3] && cols[4] && cols[5] && cols[6]) {
          cols[3] = cols[4] = cols[5] = cols[6] = false;
          ans += 1;
        }
        if (cols[5] && cols[6] && cols[7] && cols[8]) {
          cols[5] = cols[6] = cols[7] = cols[8] = false;
          ans += 1;
        }
      }
      return ans;
    }
};
