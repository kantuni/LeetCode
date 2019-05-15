class Solution {
  public:
    bool isPalindrome(string s) {
      string p;
      for (auto c: s) {
        if (isalnum(c)) {
          p += tolower(c);
        }
      }
      for (int i = 0; i < p.size(); i++) {
        if (p[i] != p[p.size() - 1 - i]) {
          return false;
        }
      }
      return true;
    }
};
