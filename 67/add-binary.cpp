class Solution {
  public:
    string addBinary(string a, string b) {
      string ans;
      int i = a.size() - 1, j = b.size() - 1;
      int carry = 0;
      while (i > -1 || j > -1 || carry == 1) {
        carry += (i > -1) ? a[i--] - '0' : 0;
        carry += (j > -1) ? b[j--] - '0' : 0;
        ans = char(carry % 2 + '0') + ans;
        carry /= 2;
      }
      return ans;
    }
};
