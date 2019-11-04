class MinStack {
  public:
    stack<pair<int, int>> s;
    
    void push(int x) {
      int smallest = s.size() > 0 ? min(x, getMin()) : x;
      s.push({x, smallest});
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
