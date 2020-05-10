class Solution {
  public:
    int findJudge(int N, vector<vector<int>>& trust) {
      vector<int> in(N), out(N);
      for (int i = 0; i < trust.size(); i++) {
        in[trust[i][1] - 1]++;
        out[trust[i][0] - 1]++;
      }
      for (int i = 0; i < N; i++) {
        if (in[i] == N - 1 and out[i] == 0) {
          return i + 1;
        }
      }
      return -1;
    }
};
