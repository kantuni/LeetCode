class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
      if (s.size() < p.size()) {
        return {};
      }
      vector<int> pc(26), sc(26);
      for (int i = 0; i < p.size(); i++) {
        pc[p[i] - 'a']++;
        sc[s[i] - 'a']++;
      }
      vector<int> ans;
      int start = 0, end = p.size() - 1;
      if (pc == sc) {
        ans.push_back(start);
      }
      while (end + 1 < s.size()) {
        sc[s[start] - 'a']--;
        start++;
        end++;
        sc[s[end] - 'a']++;
        if (pc == sc) {
          ans.push_back(start);
        }
      }
      return ans;
    }
};
