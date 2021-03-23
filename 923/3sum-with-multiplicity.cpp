class Solution {
  private:
    const int P = 1e9 + 7;

    int twoSum(map<int, long long>& memo, int target) {
      int ans = 0;
      for (auto [value, cnt]: memo) {
        int cmpl = target - value;
        if (memo.count(cmpl) == 0) {
          continue;
        }
        if (cmpl == value) {
          ans = (ans + cnt * (cnt - 1)) % P;
        } else {
          ans = (ans + cnt * memo[cmpl]) % P;
        }
      }
      return ans;
    }

  public:
    int threeSumMulti(vector<int>& arr, int target) {
      map<int, long long> memo;
      for (int i = 0; i < arr.size(); i++) {
        memo[arr[i]]++;
      }
      int ans = 0;
      for (int i = 0; i < arr.size() - 2; i++) {
        memo[arr[i]]--;
        ans = (ans + twoSum(memo, target - arr[i])) % P;
      }
      return ans / 2;
    }
};
