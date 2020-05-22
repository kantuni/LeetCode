class Solution {
  public:
    string frequencySort(string s) {
      map<char, int> memo;
      for (auto c: s) {
        memo[c]++;
      }
      set<pair<int, char>, greater<pair<int, char>>> order;
      for (auto [c, cnt]: memo) {
        order.insert({cnt, c});
      }
      string ans;
      for (auto [cnt, c]: order) {
        ans += string(cnt, c);
      }
      return ans;
    }
};
