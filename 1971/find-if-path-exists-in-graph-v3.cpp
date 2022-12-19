struct DisjointSet {
  vector<int> parent, rank;
  
  DisjointSet(int n) {
    parent.assign(n, 0);
    rank.assign(n, 0);
    iota(parent.begin(), parent.end(), 0);
  }
  
  int find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]);
  }
  
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  
  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (rank[x] > rank[y]) {
      parent[y] = x;
    } else {
      parent[x] = y;
    }
    if (rank[x] == rank[y]) {
      rank[y]++;
    }
  }
};

class Solution {
  public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      DisjointSet ds(n);
      for (auto e: edges) {
        int u = e[0], v = e[1];
        ds.merge(u, v);
      }
      return ds.same(source, destination);
    }
};
