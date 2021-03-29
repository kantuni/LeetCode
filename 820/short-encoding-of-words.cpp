class Solution {
  public:
    int minimumLengthEncoding(vector<string>& words) {
      set<string> s(words.begin(), words.end());
      for (string w: words) {
        for (int i = 1; i < w.size(); i++) {
          string sx = w.substr(i);
          if (s.count(sx) > 0) {
            s.erase(sx);
          }
        }
      }
      int ans = 0;
      for (string w: s) {
        ans += w.size() + 1;
      }
      return ans;
    }
};
