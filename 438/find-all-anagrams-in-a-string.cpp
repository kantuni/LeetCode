class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
      vector<int> ans, pc(26), sc(26);
      for (int i = 0; i < p.size(); i++) {
        pc[p[i] - 'a']++;
      }
      for (int i = 0; i < s.size(); i++) {
        sc[s[i] - 'a']++;
        if (i >= p.size()) {
          sc[s[i - p.size()] - 'a']--;
        }
        if (pc == sc) {
          ans.push_back(i - p.size() + 1);
        }
      }
      return ans;
    }
};
