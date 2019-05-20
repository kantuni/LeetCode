class Solution {
  private:
    string nextInSequence(string s) {
      string res;
      char cur = s[0];
      int cnt = 1;
      for (int i = 1; i < s.size(); i++) {
        if (s[i] == cur) {
          cnt++;
        } else {
          res += to_string(cnt) + cur;
          cur = s[i];
          cnt = 1;
        }
      }
      res += to_string(cnt) + cur;
      return res;
    }

  public:
    string countAndSay(int n) {
      string ans = "1";
      for (int i = 1; i < n; i++) {
        ans = nextInSequence(ans);
      }
      return ans;
    }
};
