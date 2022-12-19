class Solution {
  public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      vector<vector<int>> g(n);
      vector<int> color(n);
      for (auto e: edges) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        g[v].push_back(u);
      }
      queue<int> q;
      q.push(source);
      color[source] = 1;
      while (!q.empty()) {
        auto u = q.front(); q.pop();
        if (u == destination) {
          return true;
        }
        for (auto v: g[u]) {
          if (color[v] == 0) {
            q.push(v);
            color[v] = 1;
          }
        }
      }
      return false;
    }
};
