class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
      if (s.size() < p.size()) {
        return {};
      }
      vector<int> pcnt(26), scnt(26);
      for (int i = 0; i < p.size(); i++) {
        pcnt[p[i] - 'a']++;
        scnt[s[i] - 'a']++;
      }
      vector<int> ans;
      int start = 0, end = p.size() - 1;
      if (pcnt == scnt) {
        ans.push_back(start);
      }
      while (end + 1 < s.size()) {
        scnt[s[start] - 'a']--;
        start++;
        end++;
        scnt[s[end] - 'a']++;
        if (pcnt == scnt) {
          ans.push_back(start);
        }
      }
      return ans;
    }
};
