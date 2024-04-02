// Verdict: Accepted
// Complexity: O(n)

class Solution {
  public:
    bool isIdealPermutation(vector<int>& nums) {
      bool ideal = true;
      int mx = -1;
      for (int i = 0; i < nums.size() - 1; i++) {
        if (mx > nums[i + 1]) {
          ideal = false;
          break;
        }
        mx = max(mx, nums[i]);
      }
      return ideal;
    }
};
