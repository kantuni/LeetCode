class Solution {
  private:
    char encode(int n) {
      if (n >= 10) {
        return 'a' + (n - 10);
      }
      return '0' + n;
    }

  public:
    string toHex(int num) {
      auto n = (num < 0) ? UINT_MAX + num + 1: num;
      string ans;
      while (n >= 16) {
        ans += encode(n % 16);
        n /= 16;
      }
      ans += encode(n);
      reverse(ans.begin(), ans.end());
      return ans;
    }
};
