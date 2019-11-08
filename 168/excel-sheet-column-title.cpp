class Solution {
  private:
    string helper(int n) {
      if (n < 26) {
        return string(1, n + 'A');
      }
      return helper(n / 26 - 1) + helper(n % 26);
    }

  public:
    string convertToTitle(int n) {
      return helper(n - 1);
    }
};
