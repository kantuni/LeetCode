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
      if (pos >= nums.size()) {
        return 0;
      }
      int cur = nums[pos] + remember(nums, pos + 2);
      int nxt = remember(nums, pos + 1);
      return max(cur, nxt);
    }

  public:
    int rob(vector<int>& nums) {
      return solve(nums, 0);
    }
};
