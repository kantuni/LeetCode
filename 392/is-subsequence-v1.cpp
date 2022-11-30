class Solution {
  public:
    bool isSubsequence(string s, string t) {
      int i = 0;
      for (int j = 0; j < t.size(); j++) {
        if (i < s.size() and t[j] == s[i]) {
          i++;
        }
      }
      return i == s.size();
    }
};
