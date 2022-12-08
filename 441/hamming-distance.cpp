class Solution {
  public:
    int hammingDistance(int x, int y) {
      int ans = 0;
      int z = x ^ y;
      while (z > 0) {
        ans += z % 2;
        z /= 2;
      }
      return ans;
    }
};
