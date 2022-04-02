class Solution {
  private:
    bool isPalindromeSubstring(string& s, int i, int j) {
      bool isPalindrome = true;
      while (i < j) {
        if (s[i] == s[j]) {
          i++, j--;
          continue;
        }
        isPalindrome = false;
        break;
      }
      return isPalindrome;
    }

  public:
    bool validPalindrome(string s) {
      bool isPalindrome = true;
      int i = 0, j = s.size() - 1;
      while (i < j) {
        if (s[i] == s[j]) {
          i++, j--;
          continue;
        }
        bool c1 = isPalindromeSubstring(s, i + 1, j);
        bool c2 = isPalindromeSubstring(s, i, j - 1);
        return c1 or c2;
      }
      return isPalindrome;
    }
};
