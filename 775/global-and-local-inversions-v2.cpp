class Solution {
  public:
    bool isIdealPermutation(vector<int>& nums) {
      set<int> s;
      bool ideal = true;
      for (int i = nums.size() - 2; i > -1; i--) {
        int smallest = *s.begin();
        if (!s.empty() and smallest < nums[i]) {
          ideal = false;
          break;
        }
        s.insert(nums[i + 1]);
      }
      return ideal;
    }
};
