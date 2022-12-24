class Solution {
  public:
    string convertToBase7(int num) {
      if (num == 0) {
        return "0";
      }
      string ans;
      int tmp = abs(num);
      while (tmp > 0) {
        ans += to_string(tmp % 7);
        tmp /= 7;
      }
      if (num < 0) {
        ans += "-";
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};
