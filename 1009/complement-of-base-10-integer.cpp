class Solution {
  public:
    int bitwiseComplement(int N) {
      if (N == 0) {
        return 1;
      }
      int ans = 0;
      for (int p = 0; N > 0; p++) {
        ans += (1 << p) * !(N % 2);
        N /= 2;
      }
      return ans;
    }
};
