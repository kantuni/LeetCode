class Solution {
  public:
    bool isIsomorphic(string s, string t) {
      map<char, char> memo;
      for (int i = 0; i < s.size(); i++) {
        memo[s[i]] = t[i];
      }
      set<char> used;
      for (auto [from, to]: memo) {
        if (used.count(to) > 0) {
          return false;
        }
        used.insert(to);
      }
      for (int i = 0; i < s.size(); i++) {
        s[i] = memo[s[i]];
      }
      return s == t;
    }
};
