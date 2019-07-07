class Solution {
  public:
    char findTheDifference(string s, string t) {
      int ans = 0;
      for (auto c: s) {
        ans = ans xor c;
      }
      for (auto c: t) {
        ans = ans xor c;
      }
      return ans;
    }
};
