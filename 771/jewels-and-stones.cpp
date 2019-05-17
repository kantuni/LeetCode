class Solution {
  public:
    int numJewelsInStones(string J, string S) {
      map<char, int> memo;
      for (auto c: S) {
        memo[c]++;
      }
      int ans = 0;
      for (auto c: J) {
        ans += memo[c];
      }
      return ans;
    }
};
