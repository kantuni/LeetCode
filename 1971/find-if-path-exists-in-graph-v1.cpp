class Solution {
  private:
    vector<vector<int>> g;
    vector<int> color;

    bool dfs(int u, int t) {
      if (u == t) {
        return true;
      }
      color[u] = 1;
      bool found = false;
      for (int v: g[u]) {
        if (color[v] == 0) {
          found |= dfs(v, t);
        }
      }
      return found;
    }

  public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      g.resize(n);
      color.resize(n);
      for (auto e: edges) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        g[v].push_back(u);
      }
      return dfs(source, destination);
    }
};
