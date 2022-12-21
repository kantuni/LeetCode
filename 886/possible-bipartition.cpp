class Solution {
  private:
    vector<vector<int>> g;
    vector<int> color, seen;

    void paint(int u, int c) {
      color[u] = c;
      for (auto v: g[u]) {
        if (color[v] == 0) {
          paint(v, c == 1 ? 2 : 1);
        }
      }
    }

    bool check(int u) {
      seen[u] = 1;
      bool ok = true;
      for (auto v: g[u]) {
        if (color[u] == color[v]) {
          return false;
        }
        if (seen[v] == 0) {
          ok = ok and check(v);
        }
      }
      return ok;
    }

  public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
      g.resize(n);
      color.resize(n);
      for (auto dislike: dislikes) {
        int u = dislike[0] - 1;
        int v = dislike[1] - 1;
        g[u].push_back(v);
        g[v].push_back(u);
      }
      for (int u = 0; u < n; u++) {
        if (color[u] == 0) {
          paint(u, 1);
        }
      }
      seen.resize(n);
      bool ok = true;
      for (int u = 0; u < n; u++) {
        if (seen[u] == 0) {
          ok = ok and check(u);
        }
      }
      return ok;
    }
};
