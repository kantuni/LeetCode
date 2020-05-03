class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
      vector<int> cnt(26);
      for (auto c: magazine) {
        cnt[c - 'a']++;
      }
      for (auto c: ransomNote) {
        if (cnt[c - 'a'] == 0) {
          return false;
        }
        cnt[c - 'a']--;
      }
      return true;
    }
};
