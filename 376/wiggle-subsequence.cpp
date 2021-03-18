class Solution {
  public:
    int wiggleMaxLength(vector<int>& nums) {
      int n = nums.size();
      // up[i] (down[i]) refers to the length of the longest wiggle subsequence
      // obtained so far by considering the i-th element as the last element
      // of the wiggle subsequence ending with a rising (falling) wiggle.
      vector<int> up(n), down(n);
      up[0] = down[0] = 1;
      for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {
          // The sequence wiggles up, thus the element before it 
          // must be a down position.
          up[i] = down[i - 1] + 1;
          down[i] = down[i - 1];
        } else if (nums[i] < nums[i - 1]) {
          // The sequence wiggles down, thus the element before it 
          // must be an up position.
          up[i] = up[i - 1];
          down[i] = up[i - 1] + 1;
        } else {
          // Otherwise, the values remain the same.
          up[i] = up[i - 1];
          down[i] = down[i - 1];
        }
      }
      return max(up[n - 1], down[n - 1]);
    }
};
