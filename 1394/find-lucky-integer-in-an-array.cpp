class Solution {
  public:
    int findLucky(vector<int>& arr) {
      map<int, int, greater<int>> memo;
      for (auto num: arr) {
        memo[num]++;
      }
      for (auto [num, cnt]: memo) {
        if (num == cnt) {
          return num;
        }
      }
      return -1;
    }
};
