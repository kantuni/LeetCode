class Solution {
  public:
    int countElements(vector<int>& arr) {
      map<int, int> memo;
      for (auto num: arr) {
        memo[num]++;
      }
      int ans = 0;
      for (auto [num, cnt]: memo) {
        ans += memo.count(num + 1) > 0 ? cnt : 0;
      }
      return ans;
    }
};
