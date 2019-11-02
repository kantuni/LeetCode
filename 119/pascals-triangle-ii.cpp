class Solution {
  public:
    vector<int> getRow(int rowIndex) {
      vector<int> row = {1};
      while (rowIndex--) {
        vector<int> tmp;
        tmp.push_back(1);
        for (int i = 0; i < row.size() - 1; i++) {
          tmp.push_back(row[i] + row[i + 1]);
        }
        tmp.push_back(1);
        row = tmp;
      }
      return row;
    }
};
