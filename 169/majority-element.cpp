class Solution {
  public:
    int majorityElement(vector<int>& nums) {
      // Boyer-Moore Voting Algorithm
      int cnt = 0, cand = -1;
      for (auto num: nums) {
        if (cnt == 0) {
          cand = num;
        }
        if (num == cand) {
          cnt++;
        } else {
          cnt--;
        }
      }
      return cand;
    }
};
