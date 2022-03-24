class Solution {
  private:
    vector<vector<string>> ans;
    vector<string> board;
  
    bool valid(vector<string>& board, int r, int c) {
      int n = board.size();
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          bool c1 = i == r; // same row
          bool c2 = j == c; // same column
          bool c3 = i + j == r + c; // 45º diagonals
          bool c4 = i - j == r - c; // 135º diagonals
          bool nok = c1 or c2 or c3 or c4;
          if (board[i][j] == 'Q' and nok) {
            return false;
          }
        }
      }
      return true;
    }
  
    void backtrack(int r) {
      int n = board.size();
      if (r == n) {
        ans.push_back(board);
        return;
      }
      for (int c = 0; c < n; c++) {
        if (valid(board, r, c)) {
          board[r][c] = 'Q';
          backtrack(r + 1);
          board[r][c] = '.';
        }
      }
    }
  
  public:
    vector<vector<string>> solveNQueens(int n) {
      board.assign(n, string(n, '.'));
      backtrack(0);
      return ans;
    }
};
