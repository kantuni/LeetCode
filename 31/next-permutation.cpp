class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
      if (nums.size() == 1) {
        return;
      }
      // Find the first index (from the end) 
      // where nums[i] < nums[i + 1].
      int i = nums.size() - 2;
      while (i > -1) {
        if (nums[i] < nums[i + 1]) {
          break;
        }
        i--;
      }
      // Reset the index if no elements where 
      // nums[i] < nums[i + 1] where found.
      // Example: [3, 2, 1]
      int j = -1;
      if (i == -1) {
        i = 0;
        // Find the minimum element != nums[i] in nums[i + 1...].
        int mn = INT_MAX;
        for (int k = i + 1; k < nums.size(); k++) {
          if (nums[k] != nums[i] and nums[k] < mn) {
            mn = nums[k];
            j = k;
          }
        }
      } else {
        // Find the next element > nums[i] in nums[i + 1...].
        int mnd = INT_MAX;
        for (int k = i + 1; k < nums.size(); k++) {
          if (nums[k] > nums[i] and nums[k] - nums[i] < mnd) {
            mnd = nums[k] - nums[i];
            j = k;
          }
        }
      }
      // Next permutation doesn't exist.
      // Example: [1, 1]
      if (j == -1) {
        return;
      }
      // Swap nums[i] with nums[j].
      swap(nums[i], nums[j]);
      // Sort nums[i + 1...].
      sort(nums.begin() + i + 1, nums.end());
    }
};
