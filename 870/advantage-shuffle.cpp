class Solution {
  public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
      multiset<int> s(A.begin(), A.end());
      for (int i = 0; i < B.size(); i++) {
        auto it = s.upper_bound(B[i]);
        if (it == s.end()) {
          it = s.begin();
        }
        A[i] = *it;
        s.erase(it);
      }
      return A;
    }
};
