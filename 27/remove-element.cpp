class Solution {
  public:
    int removeElement(vector<int>& nums, int val) {
      int j = nums.size() - 1;
      for (int i = 0; i < j + 1; i++) {
        if (nums[i] == val) {
          swap(nums[i], nums[j]);
          i--, j--;
        }
      }
      return j + 1;
    }
};
