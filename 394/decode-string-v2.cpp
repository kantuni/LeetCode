class Solution {
  private:
    int findNextRule(string& s, int skip) {
      for (int i = skip; i < s.size(); i++) {
        if (isdigit(s[i])) {
          return i;
        }
      }
      return -1;
    }
  
    int getCount(string& s, int pos) {
      int k = 0;
      while (pos < s.size() and isdigit(s[pos])) {
        k = 10 * k + (s[pos] - '0');
        pos++;
      }
      return k;
    }
  
    int findEndOfRule(string& s, int pos) {
      int balance = 1;
      while (pos < s.size() - 1 and balance > 0) {
        pos++;
        balance += s[pos] == '[';
        balance -= s[pos] == ']';
      }
      return pos;
    }
  
    string repeat(string s, int k) {
      string t;
      for (int i = 0; i < k; i++) {
        t += s;
      }
      return t;
    }

  public:
    string decodeString(string s) {
      int start = 0, end;
      while (true) {
        int pos = findNextRule(s, start);
        if (pos == -1) {
          break;
        }
        int k = getCount(s, pos);
        start = pos + to_string(k).size() + 1;
        end = findEndOfRule(s, start);
        string encoded = s.substr(start, end - start);
        string decoded = repeat(decodeString(encoded), k);
        s = s.substr(0, pos) + decoded + s.substr(end + 1);
        start = pos + k * encoded.size();
      }
      return s;
    }
};
