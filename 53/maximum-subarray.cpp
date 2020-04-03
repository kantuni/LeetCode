class Solution {
  public:
    int maxSubArray(vector<int>& nums) {
      int ans = INT_MIN, sum = 0;
      for (int i = 0; i < nums.size(); i++) {
        sum = (sum > 0) ? sum + nums[i] : nums[i];
        ans = max(ans, sum);
      }
      return ans;
    }
};
