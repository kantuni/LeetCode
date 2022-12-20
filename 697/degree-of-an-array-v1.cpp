class Solution {
  public:
    int findShortestSubArray(vector<int>& nums) {
      int d = 0;
      map<int, int> memo;
      for (auto num: nums) {
        memo[num]++;
        d = max(d, memo[num]);
      }
      int ans = nums.size();
      for (auto [num, cnt]: memo) {
        if (cnt == d) {
          auto fit = find(nums.begin(), nums.end(), num);
          int front = fit - nums.begin();
          auto bit = find(nums.rbegin(), nums.rend(), num);
          int back = bit - nums.rbegin();
          ans = min(ans, (int) nums.size() - front - back);
        }
      }
      return ans;
    }
};
