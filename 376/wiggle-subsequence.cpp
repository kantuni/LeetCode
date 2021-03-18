class Solution {
  private:
    const int INF = 1e9;
    map<int, map<int, map<bool, int>>> memo;

    int remember(vector<int>& nums, int pos, int last, bool inc) {
      if (memo.count(pos) == 0 or memo[pos].count(last) == 0 or memo[pos][last].count(inc) == 0) {
        memo[pos][last][inc] = solve(nums, pos, last, inc);
      }
      return memo[pos][last][inc];
    }

    int solve(vector<int>& nums, int pos, int last, bool inc) {
      if (pos == nums.size()) {
        return 0;
      }
      int ans = remember(nums, pos + 1, last, inc);
      if (inc and nums[pos] > last) {
        ans = max(ans, 1 + remember(nums, pos + 1, nums[pos], false));
      } else if (!inc and nums[pos] < last) {
        ans = max(ans, 1 + remember(nums, pos + 1, nums[pos], true));
      }
      return ans;
    }

  public:
    int wiggleMaxLength(vector<int>& nums) {
      return max(
        solve(nums, 0, -INF, true),
        solve(nums, 0, INF, false)
      );
    }
};
