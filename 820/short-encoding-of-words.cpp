class Solution {
  public:
    int minimumLengthEncoding(vector<string>& words) {
      set<string> s(words.begin(), words.end());
      for (auto w: words) {
        for (int i = 1; i < w.size(); i++) {
          auto sx = w.substr(i);
          if (s.count(sx) > 0) {
            s.erase(sx);
          }
        }
      }
      int ans = 0;
      for (auto w: s) {
        ans += w.size() + 1;
      }
      return ans;
    }
};
