class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      int n = nums.size();
      vector<pair<int, int>> np(n);
      for (int i = 0; i < n; i++) {
        np[i] = {nums[i], i};
      }
      sort(np.begin(), np.end());
      for (int i = 0; i < n - 1; i++) {
        bool same = np[i].first == np[i + 1].first;
        int dist = np[i + 1].second - np[i].second;
        if (same and dist <= k) {
          return true;
        }
      }
      return false;
    }
};
