class Solution {
  public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      map<int, int> memo;
      for (auto num: nums1) {
        memo[num]++;
      }
      vector<int> ans;
      for (auto num: nums2) {
        if (memo[num] > 0) {
          ans.push_back(num);
          memo[num]--;
        }
      }
      return ans;
    }
};
