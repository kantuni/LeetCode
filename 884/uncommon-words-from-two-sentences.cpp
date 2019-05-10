class Solution {
  public:
    vector<string> uncommonFromSentences(string A, string B) {
      map<string, int> memo;
      istringstream iss(A + " " + B);
      string w;
      while (iss >> w) {
        memo[w]++;
      }
      vector<string> ans;
      for (auto [w, cnt]: memo) {
        if (cnt == 1) {
          ans.push_back(w);
        }
      }
      return ans;
    }
};
