class Solution {
  public:
    int majorityElement(vector<int>& nums) {
      map<int, int> memo;
      for (auto num: nums) {
        memo[num]++;
        if (memo[num] > nums.size() / 2) {
          return num;
        }
      }
      return -1;
    }
};
