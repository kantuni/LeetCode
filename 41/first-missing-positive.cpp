class Solution {
  public:
    int firstMissingPositive(vector<int>& nums) {
      for (int i = 0; i < nums.size(); i++) {
        // Put 1 in the 0th place, 2 in the 1st place, etc.
        // Don't touch numbers that are less than 1 or 
        // are greater than the length of the array.
        bool in = nums[i] > 0 and nums[i] - 1 < nums.size();
        if (in and nums[i] != nums[nums[i] - 1]) {
          swap(nums[i], nums[nums[i] - 1]);
          i--;
        }
      }
      int ans = 1;
      for (auto num: nums) {
        if (num != ans) {
          break;
        }
        ans++;
      }
      return ans;
    }
};
