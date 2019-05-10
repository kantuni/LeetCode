class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int, int> memo;
      for (int i = 0; i < nums.size(); i++) {
        int cmpl = target - nums[i];
        if (memo.count(cmpl) and memo[cmpl] != i) {
          return {i, memo[cmpl]};
        }
        memo[nums[i]] = i;
      }
      return {};
    }
};
