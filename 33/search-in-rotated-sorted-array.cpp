class Solution {
  private:
    int findPivotIndex(vector<int>& nums) {
      int l = 0, r = nums.size() - 1;
      while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[0] <= nums[m]) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
      return l;
    }

  public:
    int search(vector<int>& nums, int target) {
      int p = findPivotIndex(nums);
      int l = 0, r = nums.size() - 1;
      while (l <= r) {
        int m = l + (r - l) / 2;
        int mp = (m + p) % nums.size();
        if (nums[mp] == target) {
          return mp;
        }
        if (nums[mp] < target) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
      return -1;
    }
};
