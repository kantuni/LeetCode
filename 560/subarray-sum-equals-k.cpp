class Solution {
  public:
    int subarraySum(vector<int>& nums, int k) {
      map<int, int> memo;
      int ans = 0, sum = 0;
      for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        int cmpl = sum - k;
        if (cmpl == 0) {
          ans++;
        }
        if (memo.count(cmpl) > 0) {
          ans += memo[cmpl];
        }
        memo[sum]++;
      }
      return ans;
    }
};
