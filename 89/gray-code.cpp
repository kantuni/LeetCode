class Solution {
  private:
    map<string, int> color;
    vector<int> ans;
  
    void dfs(string& s) {
      int num = stoi(s, 0, 2);
      ans.push_back(num);
      color[s] = 1;
      for (int i = 0; i < (int) s.size(); i++) {
        // flip the bit
        s[i] = (s[i] == '0') ? '1': '0';
        // check that we haven't been in that state before
        if (color.count(s) == 0) {
          dfs(s);
          return;
        }
        // if we have, restore the previous value
        s[i] = (s[i] == '0') ? '1' : '0';
      }
    }
  
  public:
    vector<int> grayCode(int n) {
      string root = string(n, '0');
      dfs(root);
      return ans;
    }
};
