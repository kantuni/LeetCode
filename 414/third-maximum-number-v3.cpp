class Solution {
  public:
    int thirdMax(vector<int>& nums) {
      set<int> s;
      for (auto num: nums) {
        s.insert(num);
        // maintain a set of 3 largest elements seen so far
        if (s.size() > 3) {
          s.erase(s.begin());
        }
      }
      return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};
