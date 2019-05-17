class Solution {
  public:
    vector<int> sortedSquares(vector<int>& A) {
      vector<int> S;
      for (auto ai: A) {
        S.push_back(ai * ai);
      }
      sort(S.begin(), S.end());
      return S;
    }
};
