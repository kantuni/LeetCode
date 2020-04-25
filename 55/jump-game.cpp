class Solution {
  public:
    bool canJump(vector<int>& nums) {
      int n = nums.size();
      if (n == 1) {
        return true;
      }
      vector<int> can(n, 0);
      int lastTrue = n - 1;
      for (int i = n - 2; i > -1; i--) {
        bool nxt = nums[i] > 0 and can[i + 1];
        bool skip = i + nums[i] >= lastTrue;
        bool end = i + nums[i] >= n - 1;
        can[i] = nxt or skip or end;
        lastTrue = can[i] ? i : lastTrue;
      }
      return can[0];
    }
};
