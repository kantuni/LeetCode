class Solution {
  public:
    int subarraySum(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> ps(n + 1);
      for (int i = 1; i < n + 1; i++) {
        ps[i] = ps[i - 1] + nums[i - 1];
      }
      int ans = 0;
      for (int i = 1; i < n + 1; i++) {
        for (int j = i + 1; j < n + 1; j++) {
          if (ps[j] - ps[i] == k) {
            ans++;
          }
        }
      }
      for (int i = 1; i < n + 1; i++) {
        if (ps[i] == k) {
          ans++;
        }
      }
      return ans;
    }
};
