class Solution {
  public:
    bool checkValidString(string s) {
      int low = 0, high = 0;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
          low++, high++;
        } else if (s[i] == ')') {
          low--, high--;
        } else {
          low--, high++;
        }
        // cannot be balanced anymore
        if (high < 0) {
          return false;
        }
        // ignore negative values
        low = max(low, 0);
      }
      return low == 0;
    }
};
