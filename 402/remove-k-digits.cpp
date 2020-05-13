class Solution {
  public:
    string removeKdigits(string num, int k) {
      string ans;
      for (auto d: num) {
        while (k > 0 and !ans.empty() and ans.back() > d) {
          ans.pop_back();
          k--;
        }
        if (ans.empty() and d == '0') {
          continue;
        }
        ans.push_back(d);
      }
      while (k > 0 and !ans.empty()) {
        ans.pop_back();
        k--;
      }
      return ans.empty() ? "0" : ans;
    }
};
