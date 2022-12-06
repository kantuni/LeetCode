class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      vector<int> ans;
      set<int> s(nums.begin(), nums.end());
      for (int i = 1; i <= nums.size(); i++) {
        if (s.count(i) == 0) {
          ans.push_back(i);
        }
      }
      return ans;
    }
};
