class Solution {
  public:
    bool isIsomorphic(string s, string t) {
      map<char, int> sm, tm;
      for (int i = 0; i < s.size(); i++) {
        sm[s[i]] = tm[t[i]] = i;
      }
      for (int i = 0; i < s.size(); i++) {
        if (sm[s[i]] != tm[t[i]]) {
          return false;
        }
      }
      return true;
    }
};
