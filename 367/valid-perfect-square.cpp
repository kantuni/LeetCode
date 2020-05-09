class Solution {
  public:
    bool isPerfectSquare(int num) {
      long long low = 1, high = num;
      while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid * mid == num) {
          return true;
        }
        if (mid * mid > num) {
          high = mid;
        } else {
          low = mid;
        }
        long long nextMid = low + (high - low) / 2;
        if (mid == nextMid) {
          return false;
        }
      }
      return false;
    }
};
