class Solution {
  public:
    bool hasAllCodes(string s, int k) {
      int n = s.size();
      if (n - k + 1 < pow(2, k)) {
        return false;
      }
      unordered_set<string> bin;
      for (int i = 0; i <= n - k; i++) {
        string ss = s.substr(i, k);
        bin.insert(ss);
      }
      return bin.size() == pow(2, k);
    }
};
