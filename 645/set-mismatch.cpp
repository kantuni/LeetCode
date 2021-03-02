class Solution {
  public:
    vector<int> findErrorNums(vector<int>& nums) {
      map<int, int> memo;
      for (int i = 0; i < nums.size(); i++) {
        memo[nums[i]]++;
      }
      int duplicate, missing;
      for (int i = 1; i <= nums.size(); i++) {
        if (memo[i] == 0) {
          missing = i;
        } else if (memo[i] == 2) {
          duplicate = i;
        }
      }
      return {duplicate, missing};
    }
};
