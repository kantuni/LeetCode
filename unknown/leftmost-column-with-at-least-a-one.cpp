/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
  public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
      vector<int> dim = binaryMatrix.dimensions();
      int n = dim[0], m = dim[1];
      int x = 0, y = m - 1;
      int ans = m;
      while (x < n and y >= 0) {
        int pos = binaryMatrix.get(x, y);
        if (pos == 0) {
          x++;
        } else {
          ans = min(ans, y);
          y--;
        }
      }
      return (ans < m) ? ans : -1;
    }
};
