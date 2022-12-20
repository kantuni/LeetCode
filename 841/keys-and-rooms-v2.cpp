class Solution {
  public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      int n = rooms.size();
      vector<int> color(n);
      queue<int> q;
      q.push(0);
      color[0] = 1;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: rooms[u]) {
          if (color[v] == 0) {
            q.push(v);
            color[v] = 1;
          }
        }
      }
      for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
          return false;
        }
      }
      return true;
    }
};
