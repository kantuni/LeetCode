class Solution {
  public:
    bool validMountainArray(vector<int>& arr) {
      int n = arr.size();
      bool up = n > 1 and arr[0] < arr[1];
      int i = 0;
      while (i + 1 < n) {
        if (arr[i + 1] <= arr[i]) {
          break;
        }
        i++;
      }
      bool down = i < n - 1;
      while (i + 1 < n) {
        if (arr[i + 1] >= arr[i]) {
          down = false;
          break;
        }
        i++;
      }
      return up and down;
    }
};
