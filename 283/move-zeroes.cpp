class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
      int zi = -1;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0 and zi == -1) {
          zi = i;
        }
        if (nums[i] != 0 and zi != -1) {
          swap(nums[i], nums[zi]);
          zi++;
        }
      }
    }
};
