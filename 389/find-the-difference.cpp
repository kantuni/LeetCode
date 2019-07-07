class Solution {
  public:
    char findTheDifference(string s, string t) {
      vector<int> ms(26);
      for (auto c: s) {
        ms[c - 'a']++;
      }
      vector<int> mt(26);
      for (auto c: t) {
        mt[c - 'a']++;
      }
      char ans;
      for (int i = 0; i < 26; i++) {
        if (ms[i] != mt[i]) {
          ans = i + 'a';
          break;
        }
      }
      return ans;
    }
};
