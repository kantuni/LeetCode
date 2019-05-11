class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int l = 0, r = numbers.size() - 1;
      while (l < r) {
        if (numbers[l] + numbers[r] > target) {
          r--;
        } else if (numbers[l] + numbers[r] < target) {
          l++;
        } else {
          return {l + 1, r + 1};
        }
      }
      return {};
    }
};
