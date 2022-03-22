class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      int n = nums.size();
      if (n == 1) {
        return {nums};
      }
      vector<vector<int>> ans;
      for (int i = 0; i < n; i++) {
        vector<int> rest;
        for (int j = 0; j < i; j++) {
          rest.push_back(nums[j]);
        }
        for (int j = i + 1; j < n; j++) {
          rest.push_back(nums[j]);
        }
        vector<vector<int>> ps = permute(rest);
        for (auto p: ps) {
          p.push_back(nums[i]);
          ans.push_back(p);
        }
      }
      return ans;
    }
};
