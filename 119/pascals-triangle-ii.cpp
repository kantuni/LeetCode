class Solution {
  public:
    vector<int> getRow(int rowIndex) {
      vector<int> row = {1};
      while (rowIndex--) {
        vector<int> tmp(row.size() + 1);
        tmp[0] = 1;
        for (int i = 1; i < row.size(); i++) {
          tmp[i] = row[i - 1] + row[i];
        }
        tmp[tmp.size() - 1] = 1;
        row = tmp;
      }
      return row;
    }
};
