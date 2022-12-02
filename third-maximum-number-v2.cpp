class Solution {
  public:
    int thirdMax(vector<int>& nums) {
      int n1 = INT_MIN;
      for (auto num: nums) {
        n1 = max(num, n1);
      }
      int n2 = INT_MIN;
      for (auto num: nums) {
        if (num >= n2 and num < n1) {
          n2 = max(num, n2);
        }
      }
      int n3 = INT_MIN;
      bool found = false;
      for (auto num: nums) {
        if (num >= n3 and num < n2) {
          n3 = max(num, n3);
          found = true;
        }
      }
      return found ? n3 : n1;
    }
};
