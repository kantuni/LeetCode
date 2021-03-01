class Solution {
  public:
    int distributeCandies(vector<int>& candyType) {
      map<int, int> memo;
      for (auto type: candyType) {
        memo[type]++;
      }
      return min(memo.size(), candyType.size() / 2);
    }
};
