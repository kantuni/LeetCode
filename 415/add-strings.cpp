class Solution {
  public:
    string addStrings(string num1, string num2) {
      int i = num1.size() - 1;
      int j = num2.size() - 1;
      int digit = 0, carry = 0;
      string ans;
      while (i > -1 or j > -1) {
        int d1 = i > -1 ? num1[i] - '0' : 0;
        int d2 = j > -1 ? num2[j] - '0' : 0;
        digit = (d1 + d2 + carry) % 10;
        carry = (d1 + d2 + carry) / 10;
        ans += to_string(digit);
        i--, j--;
      }
      if (carry > 0) {
        ans += to_string(carry);
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};
