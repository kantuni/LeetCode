class Solution {
  public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
      map<string, string> memo;
      for (auto entry: knowledge) {
        memo[entry[0]] = entry[1];
      }
      string ans;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
          string key;
          for (int j = i + 1; s[j] != ')'; j++) {
            key += s[j];
          }
          if (memo.count(key) > 0) {
            ans += memo[key];
          } else {
            ans += '?';
          }
          i += key.size() + 1;
        } else {
          ans += s[i];
        }
      }
      return ans;
    }
};
