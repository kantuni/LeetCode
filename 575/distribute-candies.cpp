class Solution {
  public:
    int distributeCandies(vector<int>& candyType) {
      set<int> types(candyType.begin(), candyType.end());
      return min(types.size(), candyType.size() / 2);
    }
};
