class Solution {
  public:
    int findComplement(int num) {
      if (num == 0) {
        return 1;
      }
      int ans = 0;
      for (int p = 0; num > 0; p++) {
        ans += (1 << p) * !(num % 2);
        num /= 2;
      }
      return ans;
    }
};
