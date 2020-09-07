class Solution {
  private:
    int P = 1000000007;
    vector<vector<int>> memo;
    vector<vector<int>> allowed = {
      {4, 6},
      {6, 8},
      {7, 9},
      {4, 8},
      {0, 3, 9},
      {},
      {0, 1, 7},
      {2, 6},
      {1, 3},
      {2, 4},
    };

    int remember(int start, int cnt) {
      if (memo[start][cnt] == -1) {
        memo[start][cnt] = helper(start, cnt);
      }
      return memo[start][cnt];
    }

    int helper(int start, int cnt) {
      if (cnt == 0) {
        return 1;
      }
      if (cnt == 1) {
        return allowed[start].size();
      }
      int ans = 0;
      for (auto pos: allowed[start]) {
        ans = (ans + remember(pos, cnt - 1) % P) % P;
      }
      return ans;
    }
    
  public:
    int knightDialer(int n) {
      memo.resize(10, vector<int>(n, -1));
      int ans = 0;
      for (int i = 0; i < 10; i++) {
        ans = (ans + remember(i, n - 1) % P) % P;
      }
      return ans;
    }
};
