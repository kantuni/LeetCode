class Solution {
  public:
    int findMaxLength(vector<int>& nums) {
      map<int, vector<int>> memo;
      int cnt = 0;
      for (int i = 0; i < nums.size(); i++) {
        cnt += (nums[i] == 1) ? 1 : -1;
        memo[cnt].push_back(i);
      }
      int ans = 0;
      for (auto [key, values]: memo) {
        int len = (key == 0)
            ? values.back() + 1
            : values.back() - values.front();
        ans = max(ans, len);
      }
      return ans;
    }
};
