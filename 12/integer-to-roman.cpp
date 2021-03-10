class Solution {
  public:
    string intToRoman(int num) {
      vector<int> marks = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
      vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
      string ans;
      int pos = 0;
      while (pos < marks.size()) {
        if (marks[pos] <= num) {
          ans += romans[pos];
          num -= marks[pos];
        } else {
          pos++;
        }
      }
      return ans;
    }
};
