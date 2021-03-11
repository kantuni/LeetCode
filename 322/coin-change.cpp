class Solution {
  private:
    map<int, int> memo;
  
    int remember(vector<int>& coins, int amount) {
      if (memo.count(amount) == 0) {
        memo[amount] = coinChange(coins, amount);
      }
      return memo[amount];
    }

  public:
    int coinChange(vector<int>& coins, int amount) {
      if (amount < 0) {
        return -1;
      }
      if (amount == 0) {
        return 0;
      }
      int ans = INT_MAX;
      for (int i = 0; i < coins.size(); i++) {
        int steps = remember(coins, amount - coins[i]);
        if (steps != -1) {
          ans = min(ans, 1 + steps);
        }
      }
      return (ans == INT_MAX) ? -1 : ans;
    }
};
