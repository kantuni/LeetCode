// Verdict: Accepted
// Complexity: O(nlogn)

class Solution {
  public:
    bool isIdealPermutation(vector<int>& nums) {
      set<int> s;
      bool ideal = true;
      for (int i = nums.size() - 2; i > -1; i--) {
        if (!s.empty() and *s.begin() < nums[i]) {
          ideal = false;
          break;
        }
        s.insert(nums[i + 1]);
      }
      return ideal;
    }
};
