class Solution {
  public:
    string strWithout3a3b(int A, int B) {
      bool flip = false;
      if (B > A) {
        flip = true;
        swap(A, B);
      }
      string s;
      while (A > 1 and B > 0 and A - B > 1) {
        s += "aab";
        A -= 2, B--;
      }
      while (A > 0 and B > 0) {
        s += "ab";
        A--, B--;
      }
      while (A--) {
        s += "a";
      }
      while (B--) {
        s += "b";
      }
      for (int i = 0; flip and i < s.size(); i++) {
        s[i] = s[i] == 'b' ? 'a' : 'b';
      }
      return s;
    }
};
