class Solution {
  private:
    map<int, int> memo;

    int remember(int n) {
      if (memo.count(n) == 0) {
        memo[n] = solve(n);
      }
      return memo[n];
    }
  
    int solve(int n) {
      if (n == 0) {
        return 0;
      }
      if (n == 1) {
        return 1;
      }
      // Number of 1s in any even number n = number of 1s in n / 2.
      // Example:
      // 10 -> 1010
      // 5 -> 101
      if (n % 2 == 0) {
        return solve(n / 2);
      }
      // Number of 1s in any odd number n = 1 + number of 1s in n - 1.
      // Example:
      // 11 -> 1011
      // 10 -> 1010 (+1)
      return solve(n - 1) + 1;
    }

  public:
    vector<int> countBits(int n) {
      vector<int> ans(n + 1);
      for (int i = 0; i <= n; i++) {
        ans[i] = solve(i);
      }
      return ans;
    }
};
