class Solution {
  public:
    bool wordPattern(string p, string s) {
      istringstream iss(s);
      vector<string> words;
      string word;
      while (iss >> word) {
        words.push_back(word);
      }
      if (p.size() != words.size()) {
        return false;
      }
      map<char, string> ps;
      map<string, char> sp;
      for (int i = 0; i < p.size(); i++) {
        if (ps.count(p[i]) == 0 and sp.count(words[i]) == 0) {
          ps[p[i]] = words[i];
          sp[words[i]] = p[i];
        }
        if (ps[p[i]] != words[i] or sp[words[i]] != p[i]) {
          return false;
        }
      }
      return true;
    }
};
