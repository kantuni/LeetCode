class Solution {
  private:
    bool isSelfDividingNumber(int n) {
      int nc = n;
      while (nc > 0) {
        int d = nc % 10;
        if (d == 0) {
          // A self-dividing number is not 
          // allowed to contain the digit zero.
          return false;
        }
        if (n % d != 0) {
          return false;
        }
        nc /= 10;
      }
      return true;
    }

  public:
    vector<int> selfDividingNumbers(int left, int right) {
      vector<int> ans;
      for (int i = left; i <= right; i++) {
        if (isSelfDividingNumber(i)) {
          ans.push_back(i);
        }
      }
      return ans;
    }
};
