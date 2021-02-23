class Solution {
  private:
    map<int, int> id;
    map<int, map<int, int>> memo;
  
    bool remember(vector<int>& stones, int pos, int k) {
      if (memo.count(pos) == 0 or memo[pos].count(k) == 0) {
        memo[pos][k] = solve(stones, pos, k);
      }
      return memo[pos][k];
    }

    bool solve(vector<int>& stones, int pos, int k) {
      if (pos == stones.size() - 1) {
        return true;
      }
      bool ok = false;
      int d[] = {-1, 0, 1};
      for (int i = 0; i < 3; i++) {
        int len = k + d[i];
        if (len < 1) {
          continue;
        }
        if (id.count(stones[pos] + len) > 0) {
          ok = ok or remember(stones, id[stones[pos] + len], len);
        }
      }
      return ok;
    }

  public:
    bool canCross(vector<int>& stones) {
      for (int i = 0; i < stones.size(); i++) {
        id[stones[i]] = i;
      }
      return solve(stones, 0, 0);
    }
};
