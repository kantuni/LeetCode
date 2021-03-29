class Solution {
  private:
    static bool byLength(string& a, string& b) {
      return a.size() > b.size();
    }
  
    bool match(string a, string b) {
      int i = a.size() - 1, j = b.size() - 1;
      while (j > -1) {
        if (a[i] != b[j]) {
          return false;
        }
        i--, j--;
      }
      return true;
    }

  public:
    int minimumLengthEncoding(vector<string>& words) {
      vector<int> color(words.size());
      sort(words.begin(), words.end(), byLength);
      for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {
          if (color[j] == 0 and match(words[i], words[j])) {
            color[j] = 1;
          }
        }
      }
      int ans = 0;
      for (int i = 0; i < color.size(); i++) {
        if (color[i] == 0) {
          ans += words[i].size() + 1;
        }
      }
      return ans;
    }
};
