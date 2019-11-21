class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      int n = nums.size();
      vector<pair<int, int>> numsp(n);
      for (int i = 0; i < n; i++) {
        numsp[i] = {nums[i], i};
      }
      sort(numsp.begin(), numsp.end());
      for (int i = 0; i < n - 1; i++) {
        bool same = numsp[i + 1].first == numsp[i].first;
        int dist = numsp[i + 1].second - numsp[i].second;
        if (same and dist <= k) {
          return true;
        }
      }
      return false;
    }
};
