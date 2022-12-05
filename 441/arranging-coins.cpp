class Solution {
  public:
    int arrangeCoins(int n) {
      int ans = 0;
      for (long long i = 1; i * (i + 1) / 2 <= n; i++) {
        ans++;
      }
      return ans;
    }
};
