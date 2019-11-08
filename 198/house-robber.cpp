class Solution {
  private:
    map<int, int> memo;

    int remember(vector<int>& nums, int pos) {
      if (memo.count(pos) == 0) {
        memo[pos] = solve(nums, pos);
      }
      return memo[pos];
    }

    int solve(vector<int>& nums, int pos) {
      if (pos < 0) {
        return 0;
      }
      int take = nums[pos] + remember(nums, pos - 2);
      int skip = remember(nums, pos - 1);
      return max(take, skip);
    }

  public:
    int rob(vector<int>& nums) {
      return solve(nums, nums.size() - 1);
    }
};
