class Solution {
  public:
    vector<int> sortArray(vector<int>& nums) {
      const int M = 100001;
      vector<int> f(M);
      for (auto num: nums) {
        f[num + M / 2]++;
      }
      for (int i = 0, j = 0; i < f.size(); i++) {
        while (f[i]--) {
          nums[j++] = i - M / 2;
        }
      }
      return nums;
    }
};
