class Solution {
  private:
    vector<vector<int>> ans;
    vector<int> p, color;
  
    void helper(vector<int>& nums) {
      if (p.size() == nums.size()) {
        ans.push_back(p);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (color[i] == 1) {
          continue;
        }
        p.push_back(nums[i]);
        color[i] = 1;
        helper(nums);
        p.pop_back();
        color[i] = 0;
      }
    }

  public:
    vector<vector<int>> permute(vector<int>& nums) {
      color.assign(nums.size(), 0);
      helper(nums);
      return ans;
    }
};
