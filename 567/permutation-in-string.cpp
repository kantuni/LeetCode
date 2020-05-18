class Solution {
  public:
    bool checkInclusion(string s, string t) {
      vector<int> sc(26), tc(26);
      for (int i = 0; i < s.size(); i++) {
        sc[s[i] - 'a']++;
      }
      for (int i = 0; i < t.size(); i++) {
        tc[t[i] - 'a']++;
        if (i >= s.size()) {
          tc[t[i - s.size()] - 'a']--;
        }
        if (sc == tc) {
          return true;
        }
      }
      return false;
    }
};
