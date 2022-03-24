class Solution {
  private:
    vector<vector<string>> ans;
    vector<string> board;
  
    bool checkHorizontal(vector<string>& board) {
      int n = board.size();
      for (int r = 0; r < n; r++) {
        int q = 0;
        for (int c = 0; c < n; c++) {
          q += board[r][c] == 'Q' ? 1 : 0;
          if (q > 1) {
            return false;
          }
        }
      }
      return true;
    }
  
    bool checkVertical(vector<string>& board) {
      int n = board.size();
      for (int c = 0; c < n; c++) {
        int q = 0;
        for (int r = 0; r < n; r++) {
          q += board[r][c] == 'Q' ? 1 : 0;
          if (q > 1) {
            return false;
          }
        }
      }
      return true;
    }
  
    bool checkMainDiagonal(vector<string>& board) {
      int n = board.size();
      int q = 0;
      for (int r = 0; r < n; r++) {
        q += board[r][r] == 'Q' ? 1 : 0;
        if (q > 1) {
          return false;
        }
      }
      return true;
    }
  
    bool checkBelowMainDiagonal(vector<string>& board) {
      int n = board.size();
      for (int i = 0; i < n - 1; i++) {
        int q = 0;
        for (int r = n - 1 - i, c = 0; r < n; r++, c++) {
          q += board[r][c] == 'Q' ? 1 : 0;
          if (q > 1) {
            return false;
          }
        }
      }
      return true;
    }
  
    bool checkAboveMainDiagonal(vector<string>& board) {
      int n = board.size();
      for (int i = 0; i < n - 1; i++) {
        int q = 0;
        for (int r = 0, c = n - 1 - i; c < n; r++, c++) {
          q += board[r][c] == 'Q' ? 1 : 0;
          if (q > 1) {
            return false;
          }
        }
      }
      return true;
    }
  
    bool checkSecondaryDiagonal(vector<string>& board) {
      int n = board.size();
      int q = 0;
      for (int r = 0, c = n - 1; r < n; r++, c--) {
        q += board[r][c] == 'Q' ? 1 : 0;
        if (q > 1) {
          return false;
        }
      }
      return true;
    }
  
    bool checkBelowSecondaryDiagonal(vector<string>& board) {
      int n = board.size();
      for (int i = 1; i < n; i++) {
        int q = 0;
        for (int r = n - 1, c = i; c < n; r--, c++) {
          q += board[r][c] == 'Q' ? 1 : 0;
          if (q > 1) {
            return false;
          }
        }
      }
      return true;
    }
  
    bool checkAboveSecondaryDiagonal(vector<string>& board) {
      int n = board.size();
      for (int i = 1; i < n; i++) {
        int q = 0;
        for (int r = 0, c = n - 1 - i; c > -1; r++, c--) {
          q += board[r][c] == 'Q' ? 1 : 0;
          if (q > 1) {
            return false;
          }
        }
      }
      return true;
    }
  
    bool checkDiagonals(vector<string>& board) {
      bool c1 = checkMainDiagonal(board);
      bool c2 = checkBelowMainDiagonal(board);
      bool c3 = checkAboveMainDiagonal(board);
      bool c4 = checkSecondaryDiagonal(board);
      bool c5 = checkBelowSecondaryDiagonal(board);
      bool c6 = checkAboveSecondaryDiagonal(board);
      return c1 and c2 and c3 and c4 and c5 and c6;
    }
  
    bool valid(vector<string>& board) {
      bool c1 = checkHorizontal(board);
      bool c2 = checkVertical(board);
      bool c3 = checkDiagonals(board);
      return c1 and c2 and c3;
    }
  
    void backtrack(int r) {
      int n = board.size();
      if (r == n) {
        ans.push_back(board);
        return;
      }
      for (int c = 0; c < n; c++) {
        board[r][c] = 'Q';
        if (valid(board)) {
          backtrack(r + 1);
        }
        board[r][c] = '.';
      }
    }
  
  public:
    vector<vector<string>> solveNQueens(int n) {
      board.assign(n, string(n, '.'));
      backtrack(0);
      return ans;
    }
};
