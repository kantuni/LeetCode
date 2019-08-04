class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
      vector<int> frequency(26);
      for (char letter: magazine) {
        frequency[letter - 'a']++;
      }
      bool possible = true;
      for (char letter: ransomNote) {
        if (frequency[letter - 'a'] == 0) {
          possible = false;
          break;
        }
        frequency[letter - 'a']--;
      }
      return possible;
    }
};
