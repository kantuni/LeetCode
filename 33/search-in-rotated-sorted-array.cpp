class Solution {
  private:
    int findPivot(vector<int> &nums) {
      int pivot = 0;
      int l = 0, r = nums.size() - 1;
      while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] < nums[0]) {
          pivot = m;
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      return pivot;
    }

  public:
    int search(vector<int>& nums, int target) {
      int p = findPivot(nums);
      int ans = -1;
      int l = 0, r = nums.size() - 1;
      while (l <= r) {
        int m = l + (r - l) / 2;
        int mp = (m + p) % nums.size();
        if (nums[mp] == target) {
          ans = mp;
          break;
        } else if (nums[mp] < target) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
      return ans;
    }
};
