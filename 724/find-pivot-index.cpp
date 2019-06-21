class Solution {
  public:
    int pivotIndex(vector<int>& nums) {
      int sum = accumulate(nums.begin(), nums.end(), 0);
      int ans = -1, tmp = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (tmp == sum - tmp - nums[i]) {
          ans = i;
          break;
        }
        tmp += nums[i];
      }
      return ans;
    }
};
