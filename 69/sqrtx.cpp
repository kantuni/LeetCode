class Solution {
  public:
    int mySqrt(int x) {
      long long l = 0, h = x;
      while (l < h) {
        long long m = (l + h) / 2;
        if (m * m < x) {
          l = m + 1;
        } else {
          h = m;
        }
      }
      return (l * l > x) ? l - 1 : l;
    }
};
