class Solution {
  public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      map<int, int> m1;
      for (auto num: nums1) {
        m1[num]++;
      }
      map<int, int> m2;
      for (auto num: nums2) {
        m2[num]++;
      }
      vector<int> ans;
      for (auto [num, cnt1]: m1) {
        int cnt = min(cnt1, m2[num]);
        while (cnt--) {
          ans.push_back(num);
        }
      }
      return ans;
    }
};
