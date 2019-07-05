class Solution {
  public:
    bool isAnagram(string s, string t) {
      vector<int> sigma(26);
      for (int i = 0; i < s.size(); i++) {
        sigma[s[i] - 'a']++;
      }
      for (int i = 0; i < t.size(); i++) {
        sigma[t[i] - 'a']--;
      }
      for (int i = 0; i < 26; i++) {
        if (sigma[i] != 0) {
          return false;
        }
      }
      return true;
    }
};
