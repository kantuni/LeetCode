class Solution {
  public:
    void duplicateZeros(vector<int>& arr) {
      queue<int> q;
      for (int i = 0; i < arr.size(); i++) {
        q.push(arr[i]);
        if (arr[i] == 0) {
          q.push(0);
        }
      }
      for (int i = 0; i < arr.size(); i++) {
        arr[i] = q.front();
        q.pop();
      }
    }
};
