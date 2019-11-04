class MinStack {
  public:
    stack<pair<int, int>> s;
    
    void push(int x) {
      if (s.size() == 0) {
        s.push({x, x});
      } else {
        int smallest = min(x, s.top().second);
        s.push({x, smallest});
      }
    }
    
    void pop() {
      s.pop();
    }
    
    int top() {
      return s.top().first;
    }
    
    int getMin() {
      return s.top().second;
    }
};

