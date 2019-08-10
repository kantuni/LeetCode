class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      map<char, int> memo;
      int ans = 0;
      // sliding window [i, j]
      for (int i = 0, j = 0; j < s.size(); j++) {
        if (memo.count(s[j])) {
          i = max(i, memo[s[j]] + 1);
        }
        memo[s[j]] = j;
        ans = max(ans, j - i + 1);
      }
      return ans;
    }
};
