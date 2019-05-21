class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      vector<int> nums3(nums1.begin(), nums1.begin() + m);
      int i = 0, j = 0, k = 0;
      while (i < n and j < m) {
        if (nums2[i] < nums3[j]) {
          nums1[k] = nums2[i];
          i++, k++;
        } else {
          nums1[k] = nums3[j];
          j++, k++;
        }
      }
      while (i < n) {
        nums1[k] = nums2[i];
        i++, k++;
      }
      while (j < m) {
        nums1[k] = nums3[j];
        j++, k++;
      }
    }
};
