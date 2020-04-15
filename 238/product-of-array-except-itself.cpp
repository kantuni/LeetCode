class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
      vector<int> pp(n, 1);
      pp[0] = nums[0];
      for (int i = 1; i < n; i++) {
        pp[i] = pp[i - 1] * nums[i];
      }
      vector<int> sp(n, 1);
      sp[n - 1] = nums[n - 1];
      for (int i = n - 1; i > 0; i--) {
        sp[i - 1] = sp[i] * nums[i - 1];
      }        
      vector<int> ans(n);
      ans[0] = sp[1];
      ans[n - 1] = pp[n - 2];
      for (int i = 1; i < n - 1; i++) {
        ans[i] = pp[i - 1] * sp[i + 1];
      }
      return ans;
    }
};
