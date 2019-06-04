class Solution {
  public:
    bool canPartition(vector<int>& nums) {
      bool ans = false;
      int sum = accumulate(nums.begin(), nums.end(), 0);
      if (sum % 2 == 0) {
        int target = sum / 2;
        vector<int> memo(target + 1);
        memo[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
          for (int j = target; j >= nums[i]; j--) {
            memo[j] = memo[j] || memo[j - nums[i]];
          }
        }
        ans = memo[target];
      }
      return ans;
    }
};
