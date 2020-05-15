class Solution {
  public:
    int maxSubArray(vector<int>& nums) {
      int global = INT_MIN, local = 0;
      for (int i = 0; i < nums.size(); i++) {
        local = max(local + nums[i], nums[i]);
        global = max(global, local);
      }
      return global;
    }
};
