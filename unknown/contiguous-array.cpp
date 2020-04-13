class Solution {
  public:
    int findMaxLength(vector<int>& nums) {
      int n = nums.size();
      for (int i = 0; i < n; i++) {
        nums[i] = (nums[i] == 0) ? -1 : nums[i];
      }
      vector<int> ps(n + 1);
      for (int i = 1; i < ps.size(); i++) {
        ps[i] = ps[i - 1] + nums[i - 1];
      }
      map<int, vector<int>> memo;
      for (int i = 1; i < ps.size(); i++) {
        memo[ps[i]].push_back(i);
      }
      int ans = 0;
      for (int i = 1; i < ps.size(); i++) {
        if (ps[i] == 0) {
          ans = max(ans, i);
        }
      }
      for (auto [key, values]: memo) {
        int len = values.back() - values.front();
        ans = max(ans, len);
      }
      return ans;
    }
};
