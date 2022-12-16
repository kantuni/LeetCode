class Solution {
  public:
    void duplicateZeros(vector<int>& arr) {
      for (int i = arr.size() - 1; i > -1; i--) {
        if (arr[i] == 0) {
          arr.push_back(0);
          for (int j = arr.size() - 1; j > i; j--) {
            swap(arr[j - 1], arr[j]);
          }
          arr.pop_back();
        }
      }
    }
};
