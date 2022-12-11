class Solution {
  public:
    bool checkPerfectNumber(int n) {
      if (n == 1) {
        return false;
      }
      int m = 1;
      for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
          m += i;
          m += n / i;
        }
      }
      return n == m;
    }
};
