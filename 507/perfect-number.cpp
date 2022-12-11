class Solution {
  public:
    bool checkPerfectNumber(int num) {
      if (num == 1) {
        return false;
      }
      set<int> divisors = {1};
      for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
          divisors.insert(i);
          divisors.insert(num / i);
        }
      }
      int sum = 0;
      for (auto d: divisors) {
        sum += d;
      }
      return sum == num;
    }
};
