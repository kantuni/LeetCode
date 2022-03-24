class Solution {
  private:
    int ans;
    set<int> col, d45, d135;
  
    bool valid(int r, int c) {
      bool c1 = col.count(c) == 0; // same column
      bool c2 = d45.count(r + c) == 0; // 45º diagonals
      bool c3 = d135.count(r - c) == 0; // 135º diagonals
      return c1 and c2 and c3;
    }
  
    void backtrack(int r, int n) {
      if (r == n) {
        ans++;
        return;
      }
      for (int c = 0; c < n; c++) {
        if (valid(r, c)) {
          col.insert(c);
          d45.insert(r + c);
          d135.insert(r - c);
          backtrack(r + 1, n);
          col.erase(c);
          d45.erase(r + c);
          d135.erase(r - c);
        }
      }
    }
  
  public:
    int totalNQueens(int n) {
      backtrack(0, n);
      return ans;
    }
};
