class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
      map<int, int> memo;
      for (auto num: nums) {
        if (memo[num] > 0) {
          return true;
        }
        memo[num]++;
      }
      return false;
    }
};
