class Solution {
  public:
    bool isIsomorphic(string s, string t) {
      map<char, int> ms, mt;
      for (int i = 0; i < s.size(); i++) {
        ms[s[i]] = mt[t[i]] = i;
      }
      for (int i = 0; i < s.size(); i++) {
        if (ms[s[i]] != mt[t[i]]) {
          return false;
        }
      }
      return true;
    }
};
