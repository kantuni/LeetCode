class Solution {
  public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
      map<char, int> cb;
      for (string wb: B) {
        map<char, int> tmp;
        for (char l: wb) {
          tmp[l]++;
          cb[l] = max(cb[l], tmp[l]);
        }
      }
      vector<string> ans;
      for (string wa: A) {
        map<char, int> ca;
        for (char l: wa) {
          ca[l]++;
        }
        bool universal = true;
        for (auto [l, cnt]: cb) {
          if (ca[l] < cnt) {
            universal = false;
            break;
          }
        }
        if (universal) {
          ans.push_back(wa);
        }
      }
      return ans;
    }
};
