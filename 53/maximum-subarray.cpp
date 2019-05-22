class Solution {
  public:
    int maxSubArray(vector<int>& nums) {
      int mx = INT_MIN, cur = INT_MIN;
      for (int i = 0; i < nums.size(); i++) {
        mx = max(mx, nums[i]);
        cur = (cur > 0) ? cur + nums[i] : nums[i];
        mx = max(mx, cur);
      }
      return mx;
    }
};
