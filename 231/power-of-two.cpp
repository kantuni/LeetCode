class Solution {
  public:
    bool isPowerOfTwo(int n) {
      if (n == 0) {
        return false;
      }
      double p = log2(n);
      return ceil(p) == p;
    }
};
