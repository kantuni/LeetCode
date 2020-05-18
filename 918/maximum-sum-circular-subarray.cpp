class Solution {
  public:
    int maxSubarraySumCircular(vector<int>& A) {
      int n = A.size();
      bool allPositive = true;
      for (auto num: A) {
        if (num < 0) {
          allPositive = false;
          break;
        }
      }
      if (allPositive) {
        return accumulate(A.begin(), A.end(), 0);
      }
      int global = INT_MIN, local = 0;
      int start = 0, end = 0;
      for (int i = 0; i < 2 * n; i++) {
        if (local > 0) {
          local += A[i % n];
          end = i;
        } else {
          local = A[i % n];
          start = end = i;
        }
        if (end - start == n) {
          int bestLocal = INT_MIN, bestStart = -1;
          while (start < end) {
            local -= A[start % n];
            start++;
            if (local > bestLocal) {
              bestLocal = local;
              bestStart = start;
            }
          }
          local = bestLocal;
          start = bestStart;
        }
        global = max(global, local);
      }
      return global;
    }
};
