class Solution {
  public:
    int longestPalindrome(string s) {
      map<int, int> memo;
      for (auto c: s) {
        memo[c]++;
      }
      int ans = 0;
      bool oddLength = false;
      for (auto [c, cnt]: memo) {
        // Dividing and multiplying ensures that cases
        // such as "ccc" are not ignored.
        ans += cnt / 2;
        if (cnt % 2 == 1) {
          oddLength = true;
        }
      }
      return oddLength ? 2 * ans + 1 : 2 * ans;
    }
};
