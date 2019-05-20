class Solution {
  public:
    int searchInsert(vector<int>& nums, int target) {
      auto lower = lower_bound(nums.begin(), nums.end(), target);
      return lower - nums.begin();
    }
};
