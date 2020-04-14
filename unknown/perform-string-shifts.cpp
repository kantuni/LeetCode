class Solution {
  public:
    string stringShift(string s, vector<vector<int>>& shift) {
      int n = s.size();
      int delta = 0;
      for (auto move: shift) {
        int direction = move[0], amount = move[1];
        delta += (direction == 1) ? amount : -amount;
        delta %= n;
      }
      auto newFirstIt = (delta > 0) 
        ? s.begin() + s.size() - delta
        : s.begin() - delta;
      rotate(s.begin(), newFirstIt, s.end());
      return s;
    }
};
