class Solution {
  public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
      int n = A.size();
      vector<pair<int, int>> Ax(n), Bx(n);
      for (int i = 0; i < n; i++) {
        Ax[i] = {A[i], i};
        Bx[i] = {B[i], i};
      }
      sort(Ax.begin(), Ax.end());
      sort(Bx.begin(), Bx.end());
      map<int, int> win;
      vector<int> lose;
      int i = 0, j = 0;
      while (i < n and j < n) {
        while (i < n and Ax[i].first <= Bx[j].first) {
          lose.push_back(Ax[i].first);
          i++;
        }
        if (i == n) {
          break;
        }
        win[Bx[j].second] = Ax[i].first;
        i++, j++;
      }
      vector<int> ans;
      for (int i = 0; i < n; i++) {
        if (win.count(i) > 0) {
          ans.push_back(win[i]);
        } else {
          ans.push_back(lose.back());
          lose.pop_back();
        }
      }
      return ans;
    }
};
