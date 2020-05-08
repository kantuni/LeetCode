class Solution {
  public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
      int x1 = coordinates[0][0], y1 = coordinates[0][1];
      int x2 = coordinates[1][0], y2 = coordinates[1][1];
      for (int i = 2; i < coordinates.size(); i++) {
        int xi = coordinates[i][0], yi = coordinates[i][1];
        bool sameSlope = (y2 - y1) * (xi - x1) == (yi - y1) * (x2 - x1);
        if (!sameSlope) {
          return false;
        }
      }
      return true;
    }
};
