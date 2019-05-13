class Solution {
  public:
    int lengthOfLastWord(string s) {
      istringstream iss(s);
      string w;
      int ans = 0;
      while (iss >> w) {
        ans = w.size();
      }
      return ans;
    }
};
