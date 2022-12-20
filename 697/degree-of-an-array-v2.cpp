class Solution {
  public:
    int findShortestSubArray(vector<int>& nums) {
      int d = 0;
      map<int, int> memo, lpos, rpos;
      for (int i = 0; i < nums.size(); i++) {
        if (memo[nums[i]] == 0) {
          lpos[nums[i]] = i;
          rpos[nums[i]] = i;
        } else {
          rpos[nums[i]] = i;
        }
        memo[nums[i]]++;
        d = max(d, memo[nums[i]]);
      }
      int ans = nums.size();
      for (auto [num, cnt]: memo) {
        if (cnt == d) {
          ans = min(ans, rpos[num] - lpos[num] + 1);
        }
      }
      return ans;
    }
};
