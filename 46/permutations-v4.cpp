class Solution {
  private:
    vector<vector<int>> ans;
    
    void helper(vector<int>& nums, int i) {
      if (i == nums.size()) {
        ans.push_back(nums);
        return;
      }
      for (int j = i; j < nums.size(); j++) {
        // maintains [0...i-1] invariant
        swap(nums[i], nums[j]);
        helper(nums, i + 1);
        swap(nums[j], nums[i]);
      }
    }
  
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      helper(nums, 0);
      return ans;
    }
};
