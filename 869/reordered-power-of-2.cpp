class Solution {
  public:
    bool reorderedPowerOf2(int N) {
      string ns = to_string(N);
      sort(ns.begin(), ns.end());
      set<string> s;
      long long m = 1;
      while (m < 1e9) {
        string ms = to_string(m);
        sort(ms.begin(), ms.end());
        s.insert(ms);
        m *= 2;
      }
      return s.count(ns) > 0;
    }
};
