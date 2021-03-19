class Solution {
  private:
    vector<int> color;
  
    void dfs(vector<vector<int>>& rooms, int u) {
      color[u] = 1;
      for (auto v: rooms[u]) {
        if (color[v] == 0) {
          dfs(rooms, v);
        }
      }
    }
  
  public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      color.assign(rooms.size(), 0);
      dfs(rooms, 0);
      for (int i = 0; i < rooms.size(); i++) {
        if (color[i] == 0) {
          return false;
        }
      }
      return true;
    }
};
