class Solution {
  public:
    vector<int> getRow(int rowIndex) {
      vector<int> row(rowIndex + 1);
      row[0] = 1;
      while (rowIndex--) {
        for (int i = row.size() - 1; i > 0; i--) {
          row[i] += row[i - 1];
        }
      }
      return row;
    }
};
