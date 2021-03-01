class Solution {
  public:
    int distributeCandies(vector<int>& candyType) {
      set<int> types;
      for (auto type: candyType) {
        types.insert(type);
      }
      return min(types.size(), candyType.size() / 2);
    }
};
