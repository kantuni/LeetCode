class Solution {
  public:
    char findTheDifference(string s, string t) {
      int ans = 0;
      for (auto si: s) {
        ans = ans xor si;
      }
      for (auto ti: t) {
        ans = ans xor ti;
      }
      return ans;
    }
};
