class Solution {
  public:
    int rangeBitwiseAnd(int m, int n) {
      return (m == n) ? n : 2 * rangeBitwiseAnd(m / 2, n / 2);
    }
};
