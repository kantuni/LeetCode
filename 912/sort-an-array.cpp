class Solution {
  public:
    vector<int> sortArray(vector<int>& nums) {
      const int N = nums.size();
      const int M = 100001;
      vector<int> freq(M);
      for (auto num: nums) {
        freq[num + M / 2]++;
      }
      vector<int> sorted(N);
      for (int i = 0, j = 0; i < freq.size(); i++) {
        while (freq[i] > 0) {
          sorted[j] = i - M / 2;
          freq[i]--;
          j++;
        }
      }
      return sorted;
    }
};
