class Solution {
  private:
    bool isVowel(char c) {
      set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
      return vowels.count(tolower(c)) > 0;
    }
  
    string toLower(string s) {
      transform(s.begin(), s.end(), s.begin(), ::tolower);
      return s;
    }

    string mask(string s) {
      for (auto &c: s) {
        c = isVowel(c) ? '*' : c;
      }
      return s;
    }

  public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
      map<string, string> original, lowercase, masked;
      reverse(wordlist.begin(), wordlist.end());
      for (auto w: wordlist) {
        auto c1 = w, c2 = toLower(w), c3 = mask(toLower(w));
        original[c1] = lowercase[c2] = masked[c3] = w;
      }
      vector<string> ans;
      for (auto q: queries) {
        auto c1 = q, c2 = toLower(q), c3 = mask(toLower(q));
        if (original.count(c1) > 0) {
          ans.push_back(original[c1]);
        } else if (lowercase.count(c2) > 0) {
          ans.push_back(lowercase[c2]);
        } else if (masked.count(c3) > 0) {
          ans.push_back(masked[c3]);
        } else {
          ans.push_back("");
        }
      }
      return ans;
    }
};
