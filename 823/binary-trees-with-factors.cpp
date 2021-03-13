class Solution {
  public:
    int numFactoredBinaryTrees(vector<int>& a) {
      const long long P = 1000000007;
      map<long long, int> memo;
      for (int i = 0; i < a.size(); i++) {
        memo[a[i]] = 1;
      }
      vector<tuple<long long, int, int>> products;
      for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
          auto p = (long long) a[i] * a[j];
          if (memo.count(p) > 0) {
            products.push_back({p, a[i], a[j]});
          }
        }
      }
      sort(products.begin(), products.end());
      for (auto [p, ai, aj]: products) {
        auto left = memo[ai] % P;
        auto right = memo[aj] % P;
        memo[p] = (memo[p] + (left * right) % P) % P;
      }
      long long ans = 0;
      for (auto [_, value]: memo) {
        ans = (ans + value) % P;
      }
      return ans;
    }
};
