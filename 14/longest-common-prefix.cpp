class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
      string ans;
      if (strs.size() == 0) {
        return ans;
      }
      int n = strs[0].size();
      for (auto s: strs) {
        n = min(n, (int) s.size());
      }
      for (int j = 0; j < n; j++) {
        char l = strs[0][j];
        for (int i = 1; i < strs.size(); i++) {
          if (strs[i][j] != l) {
            return ans;
          }
        }
        ans += l;
      }
      return ans;
    }
};
