class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      for (auto it = numbers.begin(); it != numbers.end(); it++) {
        auto lower = lower_bound(it + 1, numbers.end(), target - *it);
        if (lower != numbers.end() and *lower + *it == target) {
          return {it - numbers.begin() + 1, lower - numbers.begin() + 1};
        }
      }
      return {};
    }
};
