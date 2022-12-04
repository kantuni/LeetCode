class Solution {
  public:
    int countSegments(string s) {
      int ans = 0;
      istringstream iss(s);
      string tmp;
      while (iss >> tmp) {
        ans++;
      }
      return ans;
    }
};
