class Solution {
  public:
    int singleNonDuplicate(vector<int>& nums) {
      int n = nums.size();
      int low = 0, high = n - 1;
      while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid + 1 < n and nums[mid] == nums[mid + 1]) {
          mid++;
        }
        if (mid % 2 == 1) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
      return nums[low];
    }
};
