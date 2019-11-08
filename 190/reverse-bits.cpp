class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
      vector<int> bits(32);
      for (int i = 0; n > 0; i++) {
        bits[i] = n % 2;
        n /= 2;
      }
      uint32_t ans = 0;
      for (int i = 31, j = 0; i > -1; i--, j++) {
        if (bits[i] == 1) {
          ans += (1 << j);
        }
      }
      return ans;
    }
};
