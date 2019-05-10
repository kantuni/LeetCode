class Solution {
  public:
    int reverse(int x) {
      long long rx = 0;
      while (x != 0) {
        rx *= 10;
        rx += x % 10;
        x /= 10;
      }
      if (rx < INT_MIN or rx > INT_MAX) {
        return 0;
      }
      return rx;
    }
};
