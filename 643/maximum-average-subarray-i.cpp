class Solution {
  public:
    double findMaxAverage(vector<int>& nums, int k) {
      int i = 0, j = 0;
      long long sum = 0;
      while (j < k) {
        sum += nums[j];
        j++;
      }
      double ans = 1.0 * sum / k;
      while (j < nums.size()) {
        sum -= nums[i];
        sum += nums[j];
        ans = max(ans, 1.0 * sum / k);
        i++, j++;
      }
      return ans;
    }
};
