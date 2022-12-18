class Solution {
  public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
      set<int> s1, s2;
      for (auto num: nums1) {
        s1.insert(num);
      }
      for (auto num: nums2) {
        s2.insert(num);
      }
      vector<vector<int>> ans(2);
      for (auto num: s1) {
        if (s2.count(num) == 0) {
          ans[0].push_back(num);
        }
      }
      for (auto num: s2) {
        if (s1.count(num) == 0) {
          ans[1].push_back(num);
        }
      }
      return ans;
    }
};
