class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      if (nums.size() == 1) {
        return {{}, nums};
      }
      int first = nums.front();
      vector<int> rest(next(nums.begin()), nums.end());
      vector<vector<int>> subrest = subsets(rest);
      vector<vector<int>> subfirst(subrest);
      for (auto &s: subfirst) {
        s.push_back(first);
      }
      vector<vector<int>> ans;
      for (auto s: subrest) {
        ans.push_back(s);
      }
      for (auto s: subfirst) {
        ans.push_back(s);
      }
      return ans;
    }
};
