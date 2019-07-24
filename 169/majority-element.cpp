// Boyer-Moore Voting Algorithm
class Solution {
  public:
    int majorityElement(vector<int>& nums) {   
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
