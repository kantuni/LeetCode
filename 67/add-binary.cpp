class Solution {
  public:
    string addBinary(string a, string b) {
      if (a.size() > b.size()) {
        swap(a, b);
      }
      while (a.size() != b.size()) {
        a = "0" + a;
      }
      string c;
      int carry = 0;
      for (int i = a.size() - 1; i > -1; i--) {
        int ai = a[i] - '0';
        int bi = b[i] - '0';
        int ci = (ai + bi + carry) % 2;
        c = to_string(ci) + c;
        carry = (ai + bi + carry) / 2;
      }
      return (carry > 0) ? to_string(carry) + c : c;
    }
};
