class Solution {
  public:
    string strWithout3a3b(int A, int B) {
      string s;
      while (A > 0 or B > 0) {
        bool aa = s.size() > 1 and s[s.size() - 1] == s[s.size() - 2] and s[s.size() - 1] == 'a';
        bool bb = s.size() > 1 and s[s.size() - 1] == s[s.size() - 2] and s[s.size() - 1] == 'b';
        if (aa) {
          s += "b";
          B--;
        } else if (bb) {
          s += "a";
          A--;
        } else if (A > 0 and A > B) {
          s += "a";
          A--;
        } else {
          s += "b";
          B--;
        }
      }
      return s;
    }
};
