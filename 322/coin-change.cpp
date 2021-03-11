class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
      set<int> visited;
      queue<pair<int, int>> q;
      q.push({amount, 0});
      while (!q.empty()) {
        auto [amnt, step] = q.front(); q.pop();
        if (amnt == 0) {
          return step;
        }
        if (amnt < 0) {
          continue;
        }
        for (auto coin: coins) {
          if (visited.count(amnt - coin) == 0) {
            q.push({amnt - coin, step + 1});
            visited.insert(amnt - coin);
          }
        }
      }
      return -1;
    }
};
