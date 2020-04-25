class Solution {
  public:
    bool canJump(vector<int>& nums) {
      int n = nums.size();
      int lastTrue = n - 1;
      for (int i = n - 2; i > -1; i--) {
        if (i + nums[i] >= lastTrue) {
          lastTrue = i;
        }
      }
      return lastTrue == 0;
    }
};
