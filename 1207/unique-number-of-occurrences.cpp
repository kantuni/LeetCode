class Solution {
  public:
    bool uniqueOccurrences(vector<int>& arr) {
      map<int, int> memo;
      for (auto num: arr) {
        memo[num]++;
      }
      set<int> cnts;
      for (auto [num, cnt]: memo) {
        cnts.insert(cnt);
      }
      return cnts.size() == memo.size();
    }
};
