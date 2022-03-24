class Solution {
  private:
    map<int, int> memo;
    vector<vector<int>> ans;
    vector<int> p;
    
    void helper(vector<int>& nums) {
      if (p.size() == nums.size()) {
        ans.push_back(p);
        return;
      }
      for (auto [num, cnt]: memo) {
        if (cnt == 0) {
          continue;
        }
        memo[num]--;
        p.push_back(num);
        helper(nums);
        memo[num]++;
        p.pop_back();
      }
    }
  
  public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      for (auto num: nums) {
        memo[num]++;
      }
      helper(nums);
      return ans;
    }
};
