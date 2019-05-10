class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<pair<int, int>> nis;
      for (int i = 0; i < nums.size(); i++) {
        nis.push_back({nums[i], i});
      }
      sort(nis.begin(), nis.end());
      vector<int> ans;
      for (auto it = nis.begin(); it != nis.end(); it++) {
        auto [n1, i1] = *it;
        auto key = make_pair(target - n1, 0);
        auto lower = lower_bound(it + 1, nis.end(), key);
        if (lower != nis.end()) {
          auto [n2, i2] = *lower;
          if (n2 == target - n1) {
            ans = {i1, i2};
          }
        }
      }
      return ans;
    }
};
