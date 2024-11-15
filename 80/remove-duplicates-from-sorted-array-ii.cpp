class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      map<int, int> memo;
      for (int i = 0; i < nums.size(); i++) {
        if (memo[nums[i]] < 2) {
          memo[nums[i]]++;
        } else {
          nums[i] = INT_MAX;
        }
      }
      int i = 0, j = 1;
      while (j < nums.size()) {
        if (nums[i] == INT_MAX) {
          while (j < nums.size() and nums[j] == INT_MAX) {
            j++;
          }
          if (j == nums.size()) {
            break;
          }
          swap(nums[i], nums[j]);
        }
        i++;
        j = max(j, i + 1);
      }
      while (nums.back() == INT_MAX) {
        nums.pop_back();
      }
      return nums.size();
    }
};
