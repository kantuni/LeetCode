class Solution {
  public:
    vector<int> constructRectangle(int area) {
      int l, w;
      for (int i = sqrt(area); i > 0; i--) {
        if (area % i == 0) {
          l = area / i;
          w = i;
          break;
        }
      }
      return {l, w};
    }
};
