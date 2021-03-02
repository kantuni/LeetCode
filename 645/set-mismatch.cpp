class Solution {
  public:
    vector<int> findErrorNums(vector<int>& nums) {
      vector<int> cnt(nums.size());
      for (int i = 0; i < nums.size(); i++) {
        cnt[nums[i] - 1]++;
      }
      int duplicate, missing;
      for (int i = 0; i < cnt.size(); i++) {
        if (cnt[i] == 0) {
          missing = i + 1;
        } else if (cnt[i] == 2) {
          duplicate = i + 1;
        }
      }
      return {duplicate, missing};
    }
};
