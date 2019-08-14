class Solution {
  public:
    int firstMissingPositive(vector<int>& nums) {
      for (int i = nums.size() - 1; i > -1; i--) {
        bool in = nums[i] > 0 and nums[i] - 1 < nums.size();
        if (in and nums[i] != nums[nums[i] - 1]) {
          swap(nums[i], nums[nums[i] - 1]);
          i++;
        }
      }
      int ans = 1;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != ans) {
          break;
        }
        ans++;
      }
      return ans;
    }
};
