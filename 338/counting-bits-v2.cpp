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
      if (n % 2 == 0) {
        return solve(n / 2);
      }
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
