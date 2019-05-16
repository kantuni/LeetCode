class Solution {
  public:
    int fib(int N) {
      int a = 0, b = 1, c = 1;
      for (int i = 1; i < N; i++) {
        c = a + b;
        a = b, b = c;
      }
      return (N > 0) ? c : 0;
    }
};
