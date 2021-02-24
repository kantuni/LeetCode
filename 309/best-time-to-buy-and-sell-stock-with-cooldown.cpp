class Solution {
  private:
    map<int, map<bool, int>> memo;
  
    int remember(vector<int>& prices, int pos, int own) {
      if (memo.count(pos) == 0 or memo[pos].count(own) == 0) {
        memo[pos][own] = solve(prices, pos, own);
      }
      return memo[pos][own];
    }
  
    int solve(vector<int>& prices, int pos, bool own) {
      if (pos >= prices.size()) {
        return 0;
      }
      if (own) {
        return max(
          remember(prices, pos + 1, true),
          prices[pos] + remember(prices, pos + 2, false)
        );
      } else {
        return max(
          remember(prices, pos + 1, false),
          -prices[pos] + remember(prices, pos + 1, true)
        );
      }
    }

  public:
    int maxProfit(vector<int>& prices) {
      return solve(prices, 0, false);
    }
};
