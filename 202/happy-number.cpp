class Solution {
  public:
    bool isHappy(int n) {
      set<int> memo;
      while (!memo.count(n) and n != 1) {
        memo.insert(n);
        int tmp = 0;
        while (n > 0) {
          int d = n % 10;
          tmp += d * d;
          n /= 10;
        }
        n = tmp;
      }
      return n == 1;
    }
};
