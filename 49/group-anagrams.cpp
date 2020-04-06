class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      map<string, vector<string>> memo;
      for (auto s: strs) {
        string ss = s;
        sort(ss.begin(), ss.end());
        memo[ss].push_back(s);
      }
      vector<vector<string>> ans;
      for (auto [_, g] : memo) {
        ans.push_back(g);
      }
      return ans;
    }
};
