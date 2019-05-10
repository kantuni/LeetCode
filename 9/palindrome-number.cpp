class Solution {
  public:
    bool isPalindrome(int x) {
      if (x < 0) {
        return false;
      }
      long long rx = 0;
      int xc = x;
      while (xc > 0) {
        rx *= 10;
        rx += xc % 10;
        xc /= 10;
      }
      return (x == rx) ? true : false;
    }
};
