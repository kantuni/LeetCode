class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      int n = nums.size();
      vector<vector<int>> ans;
      for (int i = 0; i < (1 << n); i++) {
        bitset<10> b(i);
        vector<int> s;
        for (int j = 0; j < n; j++) {
          if (b.test(j)) {
            s.push_back(nums[j]);
          }
        }
        ans.push_back(s);
      }
      return ans;
    }
};
