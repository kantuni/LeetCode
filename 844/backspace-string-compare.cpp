class Solution {
  public:
    bool backspaceCompare(string S, string T) {
      int i = S.size() - 1, j = T.size() - 1;
      while (i > -1 or j > -1) {
        int ss = 0;
        while (i > -1) {
          if (S[i] == '#') {
            ss++, i--;
          } else if (ss > 0) {
            ss--, i--;
          } else {
            break;
          }
        }
        int ts = 0;
        while (j > -1) {
          if (T[j] == '#') {
            ts++, j--;
          } else if (ts > 0) {
            ts--, j--;
          } else {
            break;
          }
        }
        if (i == -1 and j == -1) {
          return true;
        }
        if (i < 0 or j < 0 or S[i] != T[j]) {
          return false;
        }
        i--, j--;
      }
      return true;
    }
};
