class Solution {
  public:
    bool hasAllCodes(string s, int k) {
      if (s.size() < k) {
        return false;
      }
      set<string> bin;
      for (int i = 0; i <= s.size() - k; i++) {
        string ss = s.substr(i, k);
        bin.insert(ss);
      }
      return bin.size() == pow(2, k);
    }
};
