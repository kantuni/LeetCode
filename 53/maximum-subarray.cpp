class Solution {
  public:
    int maxSubArray(vector<int>& nums) {
      int mx = INT_MIN, sum = INT_MIN;
      for (int i = 0; i < nums.size(); i++) {
        sum = (sum > 0) ? sum + nums[i] : nums[i];
        mx = max(mx, sum);
      }
      return mx;
    }
};
