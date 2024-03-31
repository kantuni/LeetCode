class Solution {
  private:
    long long countLocalInversions(vector<int>& nums) {
      long long cnt = 0;
      for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i + 1]) {
          cnt++;
        }
      }
      return cnt;
    }

    pair<vector<int>, long long> countGlobalInversions(vector<int>& nums) {
      if (nums.size() < 2) {
        return {nums, 0};
      }
      int mid = nums.size() / 2;
      auto A = vector<int>(nums.begin(), nums.begin() + mid);
      auto B = vector<int>(nums.begin() + mid, nums.end());
      auto [Am, c1] = countGlobalInversions(A);
      auto [Bm, c2] = countGlobalInversions(B);
      auto [Cm, c3] = mergeAndCountSplitInversions(Am, Bm);
      return {Cm, c1 + c2 + c3};
    }

    pair<vector<int>, long long> mergeAndCountSplitInversions(vector<int>& A, vector<int>& B) {
      vector<int> C;
      int i = 0, j = 0;
      long long cnt = 0;
      while (i < A.size() and j < B.size()) {
        if (A[i] < B[j]) {
          C.push_back(A[i]);
          i++;
        } else {
          cnt += A.size() - i;
          C.push_back(B[j]);
          j++;
        }
      }
      while (i < A.size()) {
        C.push_back(A[i]);
        i++;
      }
      while (j < B.size()) {
        C.push_back(B[j]);
        j++;
      }
      return {C, cnt};
    }

  public:
    bool isIdealPermutation(vector<int>& nums) {
      long long local = countLocalInversions(nums);
      auto [_, global] = countGlobalInversions(nums);
      return local == global;
    }
};
