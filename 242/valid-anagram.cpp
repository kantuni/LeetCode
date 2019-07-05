class Solution {
  public:
    bool isAnagram(string s, string t) {
      map<char, int> ms;
      for (auto c: s) {
        ms[c]++;
      }
      map<char, int> mt;
      for (auto c: t) {
        mt[c]++;
      }
      return ms == mt;
    }
};
