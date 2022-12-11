class Solution {
  public:
    string licenseKeyFormatting(string s, int k) {
      string tmp;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
          continue;
        } else if (islower(s[i])) {
          tmp += toupper(s[i]);
        } else {
          tmp += s[i];
        }
      }
      string ans;
      for (int i = tmp.size() - 1, j = 0; i > -1; i--, j++) {
        if (j % k == 0) {
          ans += '-';
        }
        ans += tmp[i];
      }
      reverse(ans.begin(), ans.end());
      if (ans.back() == '-') {
        ans.pop_back();
      }
      return ans;
    }
};
