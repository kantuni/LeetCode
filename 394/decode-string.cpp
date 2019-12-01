class Solution {
  public:
    string decodeString(string s) {
      int cnt = 0, start = -1;
      for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
          start = (start == -1) ? i : start;
          cnt *= 10;
          cnt += s[i] - '0';
        } else if (s[i] == '[') {
          int bcnt = 1, bstart = i, bend = i + 1;
          while (bcnt > 0) {
            bcnt += s[bend] == '[';
            bcnt -= s[bend] == ']';
            bend++;
          }
          string sub = s.substr(bstart + 1, bend - bstart - 2);
          string rsub = decodeString(sub);
          string ans = s.substr(0, start);
          while (cnt--) {
            ans += rsub;
          }
          ans += s.substr(bend);
          return decodeString(ans);
        }
      }
      return s;
    }
};
