class Solution {
  public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
      sort(envelopes.begin(), envelopes.end());
      vector<int> dp(envelopes.size());
      int ans = 0;
      for (int i = 0; i < envelopes.size(); i++) {
        for (int j = 0; j < i; j++) {
          int wi = envelopes[i][0], hi = envelopes[i][1];
          int wj = envelopes[j][0], hj = envelopes[j][1];
          if (wj < wi and hj < hi) {
            dp[i] = max(dp[i], 1 + dp[j]);
          }
          ans = max(ans, dp[i]);
        }
      }
      return ans + 1;
    }
};
