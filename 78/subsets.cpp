class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      if (nums.size() == 1) {
        return {{}, nums};
      }
      int head = nums.front();
      vector<int> tail(next(nums.begin()), nums.end());
      vector<vector<int>> subtail = subsets(tail);
      vector<vector<int>> subhead(subtail);
      for (auto &s: subhead) {
        s.push_back(head);
      }
      vector<vector<int>> ans;
      ans.insert(ans.end(), subtail.begin(), subtail.end());
      ans.insert(ans.end(), subhead.begin(), subhead.end());
      return ans;
    }
};
