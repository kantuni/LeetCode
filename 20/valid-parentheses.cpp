class Solution {
  public:
    bool isValid(string s) {
      map<char, char> inverse = {
        {')', '('},
        {'}', '{'},
        {']', '['}
      };
      stack<char> st;
      for (auto c: s) {
        switch (c) {
          case '(':
          case '{':
          case '[': {
            st.push(c);
            break;
          }
          case ')':
          case '}':
          case ']': {
            if (st.size() == 0 or st.top() != inverse[c]) {
              return false;
            }
            st.pop();
            break;
          }
        }
      }
      return st.size() == 0;
    }
};
