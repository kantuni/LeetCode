class Solution {
  public:
    int romanToInt(string s) {
      map<char, int> memo = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
      };
      int ans = 0, i;
      for (i = 0; i < s.size() - 1; i++) {
        if (memo[s[i + 1]] > memo[s[i]]) {
          ans += memo[s[i + 1]] - memo[s[i]];
          i++;
        } else {
          ans += memo[s[i]];
        }
      }
      if (i == s.size() - 1) {
        ans += memo[s[i]];
      }
      return ans;
    }
};
