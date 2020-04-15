class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
      vector<int> pp(n + 1, 1);
      for (int i = 1; i < n; i++) {
        pp[i] = pp[i - 1] * nums[i - 1];
      }
      vector<int> sp(n + 1, 1);
      for (int i = n - 1; i > 0; i--) {
        sp[i - 1] = sp[i] * nums[i];
      }
      vector<int> ans(n);
      for (int i = 0; i < n; i++) {
        ans[i] = pp[i] * sp[i];
      }
      return ans;
    }
};
