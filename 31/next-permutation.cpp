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
      if (i != -1) {
        // Find the next element > nums[i] in nums[i + 1...].
        int j = nums.size() - 1;
        while (nums[j] <= nums[i]) {
          j--;
        }
        // Swap nums[i] with nums[j].
        swap(nums[i], nums[j]);
      }
      // Reverse nums[i + 1...].
      reverse(nums.begin() + i + 1, nums.end());
    }
};
