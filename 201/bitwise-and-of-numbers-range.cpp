class Solution {
  public:
    int rangeBitwiseAnd(int m, int n) {
      int p = 1;
      while (m != n) {
        m >>= 1;
        n >>= 1;
        p <<= 1;
      }
      return m * p;
    }
};
