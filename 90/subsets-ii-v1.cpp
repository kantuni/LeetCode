class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      int n = nums.size();
      set<vector<int>> subsets;
      for (int i = 0; i < 1 << n; i++) {
        bitset<10> b(i);
        vector<int> s;
        for (int j = 0; j < n; j++) {
          if (b.test(j)) {
            s.push_back(nums[j]);
          }
        }
        sort(s.begin(), s.end());
        subsets.insert(s);
      }
      vector<vector<int>> ans(subsets.begin(), subsets.end());
      return ans;
    }
};
