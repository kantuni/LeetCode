class Solution {
  public:
    string convertToTitle(int n) {
      if (n == 0) {
        return "";
      }
      n -= 1;
      return convertToTitle(n / 26) + string(1, 'A' + (n % 26));
    }
};
