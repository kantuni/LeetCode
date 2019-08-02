class Solution {
  private:
    set<int> memo;

  public:
    bool isHappy(int n) {
      if (n == 1) return true;
      if (memo.count(n)) return false;
      int m = 0;
      int tmp = n;
      while (tmp > 0) {
        m += (tmp % 10) * (tmp % 10);
        tmp /= 10;
      }
      memo.insert(n);
      return m != n ? isHappy(m) : false; 
    }
};
