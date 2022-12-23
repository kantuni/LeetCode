class Solution {
  public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
      int ans = 0, cur = -1;
      for (int t: timeSeries) {
        ans += duration;
        if (cur >= t) {
          ans -= cur - t + 1;
        }
        cur = t + duration - 1;
      }
      return ans;
    }
};
