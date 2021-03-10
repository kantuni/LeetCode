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
      for (auto [mark, roman]: marks) {
        while (mark <= num) {
          ans += roman;
          num -= mark;
        }
      }
      return ans;
    }
};
