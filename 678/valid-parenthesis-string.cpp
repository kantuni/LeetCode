class Solution {
  private:
    bool helper(string &s, int pos, int cnt) {
      if (pos == s.size()) {
        return cnt == 0;
      }
      if (cnt < 0) {
        return false;
      }
      if (s[pos] == '(') {
        return helper(s, pos + 1, cnt + 1);
      }
      if (s[pos] == ')') {
        return helper(s, pos + 1, cnt - 1);
      }
      return (
        helper(s, pos + 1, cnt + 1) or
        helper(s, pos + 1, cnt - 1) or
        helper(s, pos + 1, cnt)
      );
    }

  public:
    bool checkValidString(string s) {
      return helper(s, 0, 0);
    }
};
