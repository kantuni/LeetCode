class Solution {
  public:
    int dominantIndex(vector<int>& nums) {
      int mxi = max_element(nums.begin(), nums.end()) - nums.begin();
      for (int i = 0; i < nums.size(); i++) {
        if (i != mxi and nums[i] * 2 > nums[mxi]) {
          mxi = -1;
          break;
        }
      }
      return mxi;
    }
};
