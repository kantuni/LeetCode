class Solution {
  public:
    string reverseVowels(string s) {
      string vowels = "AEIOUaeiou";
      vector<int> pos;
      for (int i = 0; i < s.size(); i++) {
        if (vowels.find(s[i]) != string::npos) {
          pos.push_back(i);
        }
      }
      for (int i = 0; i < pos.size() / 2; i++) {
        swap(s[pos[i]], s[pos[pos.size() - 1 - i]]);
      }
      return s;
    }
};
