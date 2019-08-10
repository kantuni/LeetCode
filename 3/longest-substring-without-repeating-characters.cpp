class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int ans = 0, start = 0;
      for (int i = 0; i < s.size(); i++) {
        int dp = -1;
        for (int j = start; j < i; j++) {
          if (s[j] == s[i]) {
            dp = j;
            break;
          }
        }
        if (dp != -1) {
          start = dp + 1;
        }
        ans = max(ans, i - start + 1);
      }
      return ans;
    }
};
