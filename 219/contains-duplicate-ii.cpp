class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_map<int, vector<int>> memo;
      for (int i = 0; i < nums.size(); i++) {
        memo[nums[i]].push_back(i);
      }
      for (auto [key, values]: memo) {
        for (int i = 0; i < values.size() - 1; i++) {
          if (abs(values[i] - values[i + 1]) <= k) {
            return true;
          }
        }
      }
      return false;
    }
};
