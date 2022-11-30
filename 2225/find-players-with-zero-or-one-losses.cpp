class Solution {
  public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
      map<int, int> winners, losers;
      for (auto match: matches) {
        winners[match[0]]++;
        losers[match[1]]++;
      }
      vector<vector<int>> ans(2);
      // Players that have not lost any matches
      for (auto [w, c]: winners) {
        if (losers.count(w) == 0) {
          ans[0].push_back(w);
        }
      }
      // Players that have lost exactly one match
      for (auto [l, c]: losers) {
        if (c == 1) {
          ans[1].push_back(l);
        }
      }
      return ans;
    }
};
