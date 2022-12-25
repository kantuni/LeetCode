class Solution {
  public:
    vector<string> findRelativeRanks(vector<int>& score) {
      int n = score.size();
      map<int, int> memo;
      for (int i = 0; i < n; i++) {
        // Keep the negative score in the map
        // to sort it in decreasing order.
        memo[-score[i]] = i;
      }
      vector<string> ans(n);
      // This index will be equal to the relative rank
      // when iterated over the map.
      int j = 1;
      for (auto [s, i]: memo) {
        if (j == 1) {
          ans[i] = "Gold Medal";
        } else if (j == 2) {
          ans[i] = "Silver Medal";
        } else if (j == 3) {
          ans[i] = "Bronze Medal";
        } else {
          ans[i] = to_string(j);
        }
        j++;
      }
      return ans;
    }
};
