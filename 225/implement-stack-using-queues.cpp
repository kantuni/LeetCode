class MyStack {
  private:
    queue<int> q1, q2;

  public:
    // Initialize your data structure here.
    MyStack() {}
    
    // Push element x onto stack.
    void push(int x) {
      while (!q1.empty()) {
        int front = q1.front(); q1.pop();
        q2.push(front);
      }
      q1.push(x);
      while (!q2.empty()) {
        int front = q2.front(); q2.pop();
        q1.push(front);
      }
    }
    
    // Removes the element on top of the stack and returns that element.
    int pop() {
      int front = q1.front(); q1.pop();
      return front;
    }
    
    // Get the top element.
    int top() {
      return q1.front();
    }
    
    // Returns whether the stack is empty.
    bool empty() {
      return q1.empty();
    }
};
