class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      int i = 0;
      for (int j = 0; j < nums.size(); j++) {
        if (nums[i] != nums[j]) {
          nums[i + 1] = nums[j];
          i++;
        }
      }
      return (nums.size() > 0) ? i + 1 : 0;
    }
};
