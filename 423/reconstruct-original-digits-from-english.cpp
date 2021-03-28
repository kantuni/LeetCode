class Solution {
  public:
    string originalDigits(string s) {
      map<char, int> cnt;
      for (auto c: s) {
        cnt[c]++;
      }
      vector<string> en = {
        "zero", "one", "two", "three", 
        "four", "five", "six", "seven", 
        "eight", "nine"
      };
      vector<pair<int, char>> order = {
        // This order uniquely identifies the digits.
        {0, 'z'}, {2, 'w'}, {4, 'u'}, {6, 'x'}, {8, 'g'},
        {1, 'o'}, {3, 'r'}, {5, 'f'}, {7, 's'}, {9, 'i'}
      };
      string ans;
      for (auto [d, c]: order) {
        int n = cnt[c];
        ans += string(n, d + '0');
        for (auto l: en[d]) {
          cnt[l] -= n;
        }
      }
      sort(ans.begin(), ans.end());
      return ans;
    }
};
