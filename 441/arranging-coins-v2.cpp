class Solution {
  public:
    int arrangeCoins(int n) {
      long long l = 1, h = n;
      while (l <= h) {
        long long m = (l + h) / 2;
        long long tmp = m * (m + 1) / 2;
        if (tmp > n) {
          h = m - 1;
        } else {
          l = m + 1;
        }
      }
      return l - 1;
    }
};
