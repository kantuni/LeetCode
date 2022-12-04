class Solution {
  public:
    int countSegments(string s) {
      int ans = 0;
      bool isSegment = false;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
          isSegment = false;
        } else {
          // this is a start of a new segment
          if (!isSegment) {
            ans++;
          }
          isSegment = true;
        }
      }
      return ans;
    }
};
