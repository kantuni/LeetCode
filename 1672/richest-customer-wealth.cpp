class Solution {
  public:
    int maximumWealth(vector<vector<int>>& accounts) {
      int ans = 0;
      for (int r = 0; r < accounts.size(); r++) {
        int sum = 0;
        for (int c = 0; c < accounts[r].size(); c++) {
          sum += accounts[r][c];
        }
        ans = max(ans, sum);
      }
      return ans;
    }
};
