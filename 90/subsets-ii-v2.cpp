class Solution {
  private:
    set<vector<int>> subsets;
    vector<int> s;
  
    void search(vector<int>& nums, int i) {
      if (i == nums.size()) {
        // Do NOT modify `s`.
        vector<int> sc = s;
        sort(sc.begin(), sc.end());
        subsets.insert(sc);
        return;
      }
      s.push_back(nums[i]);
      search(nums, i + 1);
      s.pop_back();
      search(nums, i + 1);
    }

  public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      search(nums, 0);
      vector<vector<int>> ans(subsets.begin(), subsets.end());
      return ans;
    }
};
