class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
      vector<int> freq(26);
      for (auto l: magazine) {
        freq[l - 'a']++;
      }
      bool ok = true;
      for (auto l: ransomNote) {
        if (freq[l - 'a'] == 0) {
          ok = false;
          break;
        }
        freq[l - 'a']--;
      }
      return ok;
    }
};
