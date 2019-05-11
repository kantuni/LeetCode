class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
      string ans;
      if (strs.size() == 0) {
        return ans;
      }
      int ml = INT_MAX;
      for (auto s: strs) {
        ml = min(ml, (int) s.size());
      }
      for (int j = 0; j < ml; j++) {
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

