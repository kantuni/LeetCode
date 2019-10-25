class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int pmn = INT_MAX, ans = 0;
      for (int i = 0; i < prices.size(); i++) {
        pmn = min(pmn, prices[i]);
        ans = max(ans, prices[i] - pmn);
      }
      return ans;
    }
};
