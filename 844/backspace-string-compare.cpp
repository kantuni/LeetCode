class Solution {
  private:
    void applyBackspaces(string &S) {
      for (int i = 0; i < S.size(); i++) {
        int skip = 0;
        while (i < S.size() and S[i] == '#') {
          S[i] = '+';
          skip++, i++;
        }
        for (int j = i - 1 - skip; j > -1 and skip > 0; j--) {
          if (S[j] != '+') {
            skip--;
          }
          S[j] = '+';
        }
      }
    }

  public:
    bool backspaceCompare(string S, string T) {
      applyBackspaces(S);
      applyBackspaces(T);
      int n = S.size(), m = T.size();
      int sc = 0, tc = 0;
      int i = 0, j = 0;
      while (i < n or j < m) {
        while (i < n and S[i] == '+') {
          i++;
        }
        while (j < m and T[j] == '+') {
          j++;
        }
        if (i < n and j < m and S[i] != T[j]) {
          return false;
        }
        if (i < n) {
          sc++, i++;
        }
        if (j < m) {
          tc++, j++;
        }
      }
      return i == n and j == m and sc == tc;
    }
};
