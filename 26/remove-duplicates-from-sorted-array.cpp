class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      for (int i = 0; i < nums.size(); i++) {
        auto upper = upper_bound(nums.begin(), nums.end(), nums[i]);
        auto start = i + nums.begin();
        if (start != upper - 1) {
          nums.erase(start + 1, upper);
        }
      }
      return nums.size();
    }
};
