class Solution {
  public:
    vector<int> constructRectangle(int area) {
      int l, w;
      for (int i = sqrt(area); i > 0; i--) {
        if (area % i == 0) {
          l = max(i, area / i);
          w = min(i, area / i);
          break;
        }
      }
      return {l, w};
    }
};
