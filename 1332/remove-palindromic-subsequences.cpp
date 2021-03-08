class Solution {
  private:
    bool isPalindrome(string s) {
      for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size() - 1 - i]) {
          return false;
        }
      }
      return true;
    }

  public:
    int removePalindromeSub(string s) {
      if (s.size() == 0) {
        return 0;
      }
      int a = count(s.begin(), s.end(), 'a') > 0;
      int b = count(s.begin(), s.end(), 'b') > 0;
      return isPalindrome(s) ? 1 : a + b;
    }
};
