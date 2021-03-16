class Solution {
  private:
    map<int, map<bool, int>> memo;
  
    int remember(vector<int>& prices, int fee, int pos, bool own) {
      if (memo.count(pos) == 0 or memo[pos].count(own) == 0) {
        memo[pos][own] = solve(prices, fee, pos, own);
      }
      return memo[pos][own];
    }
  
    int solve(vector<int>& prices, int fee, int pos, bool own) {
      if (pos == prices.size()) {
        return 0;
      }
      if (own) {
        return max(
          remember(prices, fee, pos + 1, true),
          prices[pos] + remember(prices, fee, pos + 1, false)
        );
      } else {
        return max(
          remember(prices, fee, pos + 1, false),
          -prices[pos] - fee + remember(prices, fee, pos + 1, true)
        );
      }
    }

  public:
    int maxProfit(vector<int>& prices, int fee) {
      return solve(prices, fee, 0, false);
    }
};
