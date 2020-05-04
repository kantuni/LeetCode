class NumArray {
  private:
    vector<int> ps;

  public:
    NumArray(vector<int>& nums) {
      ps.resize(nums.size() + 1);
      for (int i = 1; i < ps.size(); i++) {
        ps[i] = ps[i - 1] + nums[i - 1];
      }
    }
    
    int sumRange(int i, int j) {
      return ps[j + 1] - ps[i];
    }
};
