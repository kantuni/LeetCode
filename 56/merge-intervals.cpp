class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());
      vector<vector<int>> ans;
      int start = intervals[0][0], end = intervals[0][1];
      for (int i = 1; i < intervals.size(); i++) {
        int l = intervals[i][0], r = intervals[i][1];
        if (end < l) {
          ans.push_back({start, end});
          start = l;
        }
        end = max(end, r);
      }
      ans.push_back({start, end});
      return ans;
    }
};
