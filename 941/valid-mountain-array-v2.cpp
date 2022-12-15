class Solution {
  public:
    bool validMountainArray(vector<int>& arr) {
      int n = arr.size();
      // 2 pointers from left and right should meet
      // at the same location, which can't be the beginning
      // or the end of the array.
      int i = 0;
      while (i + 1 < n and arr[i] < arr[i + 1]) {
        i++;
      }
      int j = n - 1;
      while (j > 0 and arr[j - 1] > arr[j]) {
        j--;
      }
      return i > 0 and j < n - 1 and i == j;
    }
};
