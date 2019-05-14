class Solution {
  public:
    vector<int> sortArrayByParity(vector<int>& A) {
      vector<int> B, C;
      for (auto num: A) {
        if (num % 2 == 0) {
          B.push_back(num);
        } else {
          C.push_back(num);
        }
      }
      B.insert(B.end(), C.begin(), C.end());
      return B;
    }
};
