class Solution {
  private:
    bool isPalindrome(string s) {
      string rs(s.rbegin(), s.rend());
      return s == rs;
    }

  public:
    bool validPalindrome(string s) {
      bool ok = true;
      int i = 0, j = s.size() - 1;
      while (i < j) {
        if (s[i] == s[j]) {
          i++, j--;
          continue;
        }
        // [i + 1...j]
        string s1 = s.substr(i + 1, j - i);
        // [i...j - 1]
        string s2 = s.substr(i, j - i);
        return isPalindrome(s1) or isPalindrome(s2);
      }
      return ok;
    }
};
