class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
      vector<int> ans(n, 1);
      for (int i = 1, p = 1; i < n; i++) {
        ans[i] *= nums[i - 1] * p;
        p *= nums[i - 1];
      }
      for (int i = n - 1, p = 1; i > 0; i--) {
        ans[i - 1] *= nums[i] * p;
        p *= nums[i];
      }
      return ans;
    }
};
