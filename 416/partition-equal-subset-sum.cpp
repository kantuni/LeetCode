class Solution {
  public:
    bool canPartition(vector<int>& nums) {
      int n = nums.size();
      int sum = accumulate(nums.begin(), nums.end(), 0);
      bool ans = false;
      if (sum % 2 == 0) {
        int target = sum / 2;
        vector<vector<int>> memo(n + 1, vector<int>(target + 1));
        for (int i = 0; i < n + 1; i++) {
          memo[i][0] = 1;
        }
        for (int i = 1; i < n + 1; i++) {
          for (int j = 0; j < nums[i - 1] and j < target + 1; j++) {
            memo[i][j] = memo[i - 1][j];
          }
          for (int j = nums[i - 1]; j < target + 1; j++) {
            memo[i][j] = memo[i - 1][j] || memo[i - 1][j - nums[i - 1]];
          }
        }
        ans = memo[n][target];
      }
      return ans;
    }
};
