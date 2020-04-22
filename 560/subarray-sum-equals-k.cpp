class Solution {
  public:
    int subarraySum(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> ps(n + 1);
      for (int i = 1; i < n + 1; i++) {
        ps[i] = ps[i - 1] + nums[i - 1];
      }
      int ans = 0;
      map<int, int> memo;
      for (int i = 1; i < n + 1; i++) {
        int cmpl = ps[i] - k;
        if (cmpl == 0) {
          ans++;
        }
        if (memo.count(cmpl) > 0) {
          ans += memo[cmpl];
        }
        memo[ps[i]]++;
      }
      return ans;
    }
};
