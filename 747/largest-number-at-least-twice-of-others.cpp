class Solution {
  public:
    int dominantIndex(vector<int>& nums) {
      int mx = -1, mxi = -1;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > mx) {
          mx = nums[i];
          mxi = i;
        }
      }
      for (int i = 0; i < nums.size(); i++) {
        if (i == mxi) continue;
        if (nums[i] * 2 > mx) {
          mxi = -1;
          break;
        }
      }
      return mxi;
    }
};
