class Solution {
  public:
    bool isHappy(int n) {
      set<int> memo;
      while (!memo.count(n) and n != 1) {
        memo.insert(n);
        int m = 0;
        while (n > 0) {
          m += (n % 10) * (n % 10);
          n /= 10;
        }
        n = m;
      }
      return n == 1;
    }
};
