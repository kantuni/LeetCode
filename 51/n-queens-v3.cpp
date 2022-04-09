class Solution {
  private:
    vector<vector<string>> ans;
    vector<string> board;
    set<int> cols, main, secondary;
  
    bool valid(int r, int c) {
      bool c1 = cols.count(c) == 0; // same column
      bool c2 = main.count(r + c) == 0; // 45º diagonals
      bool c3 = secondary.count(r - c) == 0; // 135º diagonals
      return c1 and c2 and c3;
    }
  
    void backtrack(int r, int n) {
      if (r == n) {
        ans.push_back(board);
        return;
      }
      for (int c = 0; c < n; c++) {
        if (valid(r, c)) {
          board[r][c] = 'Q';
          cols.insert(c);
          main.insert(r + c);
          secondary.insert(r - c);
          backtrack(r + 1, n);
          board[r][c] = '.';
          cols.erase(c);
          main.erase(r + c);
          secondary.erase(r - c);
        }
      }
    }
  
  public:
    vector<vector<string>> solveNQueens(int n) {
      board.assign(n, string(n, '.'));
      backtrack(0, n);
      return ans;
    }
};
