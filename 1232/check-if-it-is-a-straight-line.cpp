class Solution {
  public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
      int n = coordinates.size();
      if (n <= 2) {
        return true;
      }
      bool sameX = true;
      for (int i = 0; i < n - 1; i++) {
        if (coordinates[i][0] != coordinates[i + 1][0]) {
          sameX = false;
          break;
        }
      }
      bool sameY = true;
      for (int i = 0; i < n - 1; i++) {
        if (coordinates[i][1] != coordinates[i + 1][1]) {
          sameY = false;
          break;
        }
      }
      if (sameX or sameY) {
        return true;
      }
      int x1 = coordinates[0][0], y1 = coordinates[0][1];
      int x2 = coordinates[1][0], y2 = coordinates[1][1];
      for (int i = 2; i < n; i++) {
        int xi = coordinates[i][0], yi = coordinates[i][1];
        bool sameSlope = (y2 - y1) * (xi - x1) == (yi - y1) * (x2 - x1);
        if (!sameSlope) {
          return false;
        }
      }
      return true;
    }
};
