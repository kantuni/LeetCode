class MyQueue {
  private:
    stack<int> s1, s2;
    int front;

  public:
    // Initialize your data structure here.
    MyQueue() {
    }
    
    // Push element x to the back of queue.
    void push(int x) {
      if (s1.empty()) {
        front = x;
      }
      s1.push(x);
    }
    
    // Removes the element from in front of queue 
    // and returns that element.
    int pop() {
      if (s2.empty()) {
        while (!s1.empty()) {
          int top = s1.top(); s1.pop();
          s2.push(top);
        }
      }
      int top = s2.top(); s2.pop();
      return top;
    }
    
    // Get the front element.
    int peek() {
      if (!s2.empty()) {
        return s2.top();
      }
      return front;
    }
    
    // Returns whether the queue is empty.
    bool empty() {
      return s1.empty() and s2.empty();
    }
};
