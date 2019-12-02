class Solution {
  private:
    bool intersect(int l1, int r1, int l2, int r2) {
      if (r1 <= l2 or r2 <= l1) {
        return false;
      }
      return true;
    }

  public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
      int ax1 = rec1[0], ax2 = rec1[2];
      int ay1 = rec1[1], ay2 = rec1[3];
      int bx1 = rec2[0], bx2 = rec2[2];
      int by1 = rec2[1], by2 = rec2[3];
      bool intersectOnX = intersect(ax1, ax2, bx1, bx2);
      bool intersectOnY = intersect(ay1, ay2, by1, by2);
      return intersectOnX and intersectOnY;
    }
};
