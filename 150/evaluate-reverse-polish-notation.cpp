class Solution {
  public:
    int evalRPN(vector<string>& tokens) {
      stack<long long> s;
      for (auto t: tokens) {
        if (t == "+") {
          long long a = s.top(); s.pop();
          long long b = s.top(); s.pop();
          s.push(b + a);
        } else if (t == "-") {
          long long a = s.top(); s.pop();
          long long b = s.top(); s.pop();
          s.push(b - a);
        } else if (t == "*") {
          long long a = s.top(); s.pop();
          long long b = s.top(); s.pop();
          s.push(b * a);
        } else if (t == "/") {
          long long a = s.top(); s.pop();
          long long b = s.top(); s.pop();
          s.push(b / a);
        } else {
          s.push(stoi(t));
        }
      }
      return s.top();
    }
};
