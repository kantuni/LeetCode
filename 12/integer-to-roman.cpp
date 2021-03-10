class Solution {
  public:
    string intToRoman(int num) {
      vector<pair<int, string>> marks = {
        {1000, "M"}, {900, "CM"}, 
        {500, "D"}, {400, "CD"}, 
        {100, "C"}, {90, "XC"},
        {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"},
        {5, "V"}, {4, "IV"},
        {1, "I"}
      };
      string ans;
      int pos = 0;
      while (pos < marks.size()) {
        auto [mark, roman] = marks[pos];
        if (mark <= num) {
          ans += roman;
          num -= mark;
        } else {
          pos++;
        }
      }
      return ans;
    }
};
