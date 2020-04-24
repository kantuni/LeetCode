class Solution {
  public:
    int rangeBitwiseAnd(int m, int n) {
      return (m == n) ? m : 2 * rangeBitwiseAnd(m / 2, n / 2);
    }
};
