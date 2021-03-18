class Solution {
  public:
    int wiggleMaxLength(vector<int>& nums) {
      int down = 1, up = 1;
      for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
          // The sequence wiggles up, thus the element before it 
          // must be a down position.
          up = down + 1;
        } else if (nums[i] < nums[i - 1]) {
          // The sequence wiggles down, thus the element before it 
          // must be an up position.
          down = up + 1;
        }
        // Otherwise, the values of up and down should remain the same.
      }
      return max(down, up);
    }
};
