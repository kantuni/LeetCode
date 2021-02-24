class FirstUnique {
  private:
    queue<int> q;
    map<int, int> memo;

  public:
    FirstUnique(vector<int>& nums) {
      for (auto num: nums) {
        add(num);
      }
    }
    
    int showFirstUnique() {
      while (!q.empty()) {
        int front = q.front();
        if (memo[front] == 1) {
          return front;
        }
        q.pop();
      }
      return -1;
    }
    
    void add(int value) {
      if (memo.count(value) == 0) {
        q.push(value);
      }
      memo[value] += 1;
    }
};
