class Solution {
  public:
    vector<int> plusOne(vector<int>& digits) {
      int carry = 1;
      for (int i = digits.size() - 1; i > -1; i--) {
        int tmp = digits[i] + carry;
        digits[i] = tmp % 10;
        carry = tmp / 10;
      }
      if (carry > 0) {
        digits.insert(digits.begin(), carry);
      }
      return digits;
    }
};
