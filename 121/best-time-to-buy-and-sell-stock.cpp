class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<int> mx(n);
      for (int i = n - 2; i > -1; i--) {
        mx[i] = max(mx[i + 1], prices[i + 1]);
      }
      int ans = 0;
      for (int i = 0; i < n; i++) {
        ans = max(ans, mx[i] - prices[i]);
      }
      return ans;
    }
};
