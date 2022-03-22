class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      map<int, int> memo;
      for (auto num: nums) {
        memo[num]++;
      }
      vector<vector<int>> ans = {{}};
      for (auto [num, cnt]: memo) {
        int n = ans.size();
        for (int i = 0; i < n; i++) {
          vector<int> s = ans[i];
          for (int j = 0; j < cnt; j++) {
            s.push_back(num);
            ans.push_back(s);
          }
        }
      }
      return ans;
    }
};
