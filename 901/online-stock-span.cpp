class StockSpanner {
  vector<int> prices, drops;

  public:
    int next(int price) {
      int n = prices.size();
      if (n > 0 and prices[n - 1] > price) {
        drops.push_back(n - 1);
      }
      prices.push_back(price);
      for (int i = drops.size() - 1; i > -1; i--) {
        if (price < prices[drops[i]]) {
          return n - drops[i];
        }
      }
      return n + 1;
    }
};
