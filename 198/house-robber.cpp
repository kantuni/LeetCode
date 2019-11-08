class Solution {
  private:
    map<int, int> memo;

    int remember(vector<int>& nums, int index) {
      if (memo.count(index) == 0) {
        memo[index] = solve(nums, index);
      }
      return memo[index];
    }

    int solve(vector<int>& nums, int index) {
      if (index >= nums.size()) {
        return 0;
      }
      int cur = nums[index] + remember(nums, index + 2);
      int nxt = remember(nums, index + 1);
      return max(cur, nxt);
    }

  public:
    int rob(vector<int>& nums) {
      return solve(nums, 0);
    }
};
