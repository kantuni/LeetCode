class Solution {
  public:
    vector<int> sortArray(vector<int>& nums) {
      const int M = 100001;
      vector<int> freq(M);
      for (auto num: nums) {
        freq[num + M / 2]++;
      }
      for (int i = 0, j = 0; i < freq.size(); i++) {
        while (freq[i]--) {
          nums[j++] = i - M / 2;
        }
      }
      return nums;
    }
};
