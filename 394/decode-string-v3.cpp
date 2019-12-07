class Solution {
  public:
    string decodeString(string s) {
      stack<string> encoded;
      stack<int> cnt;
      string ans;
      int k = 0;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '[') {
          encoded.push(ans);
          cnt.push(k);
          ans.clear();
          k = 0;
        } else if (s[i] == ']') {
          string tmp = encoded.top(); encoded.pop();
          int n = cnt.top(); cnt.pop();
          while (n--) {
            tmp += ans;
          }
          ans = tmp;
        } else if (isdigit(s[i])) {
          k = 10 * k + (s[i] - '0');
        } else {
          ans += s[i];
        }
      }
      return ans;
    }
};
