class Solution {
  public:
    int findNumbers(vector<int>& nums) {
      int ans = 0;
      for (int num: nums) {
        int d = to_string(num).size();
        if (d % 2 == 0) {
          ans++;
        }
      }
      return ans;
    }
};
