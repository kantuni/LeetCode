class Solution {
  public:
    int findMin(vector<int>& nums) {
      int ans = nums[0];
      int l = 0, r = nums.size() - 1;
      while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] < nums[0]) {
          ans = nums[m];
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      return ans;
    }
};
