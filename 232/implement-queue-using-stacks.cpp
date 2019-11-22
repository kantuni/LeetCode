class MyQueue {
  private:
    stack<int> s1, s2;

  public:
    // Initialize your data structure here.
    MyQueue() {
    }
    
    // Push element x to the back of queue.
    void push(int x) {
      while (!s1.empty()) {
        int top = s1.top(); s1.pop();
        s2.push(top);
      }
      s1.push(x);
      while (!s2.empty()) {
        int top = s2.top(); s2.pop();
        s1.push(top);
      }
    }
    
    // Removes the element from in front of queue 
    // and returns that element.
    int pop() {
      int top = s1.top(); s1.pop();
      return top;
    }
    
    // Get the front element.
    int peek() {
      return s1.top();
    }
    
    // Returns whether the queue is empty.
    bool empty() {
      return s1.empty();
    }
};
