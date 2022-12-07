class Solution {
  private:
    string repeat(string s, int n) {
      string res;
      for (int i = 0; i < n; i++) {
        res += s;
      }
      return res;
    }
  
  public:
    bool repeatedSubstringPattern(string s) {
      int slen = s.size();
      for (int k = 1; k <= slen / 2; k++) {
        if (slen % k == 0) {
          string ss = s.substr(0, k);
          string repeated = repeat(ss, slen / k);
          if (repeated == s) {
            return true;
          }
        }
      }
      return false;
    }
};
