class Solution {
  public:
    int thirdMax(vector<int>& nums) {
      set<int> s;
      for (auto num: nums) {
        s.insert(num);
      }
      vector<int> rs(s.rbegin(), s.rend());
      int ans = rs.size() > 2 ? rs[2] : rs[0];
      return ans;
    }
};
