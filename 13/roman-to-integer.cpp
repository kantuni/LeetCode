class Solution {
  public:
    int romanToInt(string s) {
      map<string, int> memo = {
        {"I", 1}, {"IV", 4},
        {"V", 5}, {"IX", 9},
        {"X", 10}, {"XL", 40},
        {"L", 50}, {"XC", 90},
        {"C", 100}, {"CD", 400},
        {"D", 500}, {"CM", 900},
        {"M", 1000}
      };
      int ans = 0, i;
      for (i = 0; i < s.size() - 1; i++) {
        string cur = string(1, s[i]);
        string nxt = string(1, s[i + 1]);
        if (memo[nxt] > memo[cur]) {
          ans += memo[cur + nxt];
          i++;
        } else {
          ans += memo[cur];
        }
      }
      if (i == s.size() - 1) {
        ans += memo[string(1, s[i])];
      }
      return ans;
    }
};
