class Solution {
  public:
    int arrangeCoins(int n) {
      // We need to find k such that
      // k * (k + 1) / 2 <= n
      // k^2 + k <= 2 * n
      
      // We'll use the fact that
      // (k + 0.5)^2 = k^2 + k + 0.25
      
      // Thus, we get
      // (k + 0.5)^2 - 0.25 <= 2 * n
      // (k + 0.5) <= sqrt(2 * n + 0.25)
      // k <= sqrt(2 * n + 0.25) - 0.5

      // NOTE: We use 2.0 instead of 2 to convert
      // the int to float to avoid integer overflow.
      return sqrt(2.0 * n + 0.25) - 0.5;
    }
};
