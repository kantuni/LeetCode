class Solution {
  private:
    bool solve(string &s, int pos, int cnt) {
      if (pos == s.size()) {
        return cnt == 0;
      }
      if (cnt < 0) {
        return false;
      }
      if (s[pos] == '(') {
        return solve(s, pos + 1, cnt + 1);
      }
      if (s[pos] == ')') {
        return solve(s, pos + 1, cnt - 1);
      }
      return (
        solve(s, pos + 1, cnt + 1) or
        solve(s, pos + 1, cnt - 1) or
        solve(s, pos + 1, cnt)
      );
    }

  public:
    bool checkValidString(string s) {
      return solve(s, 0, 0);
    }
};
