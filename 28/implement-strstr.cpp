class Solution {
  public:
    int strStr(string haystack, string needle) {
      if (needle.size() == 0) {
        return 0;
      }
      if (needle.size() > haystack.size()) {
        return -1;
      }
      for (int i = 0; i < haystack.size(); i++) {
        bool found = true;
        for (int j = 0; j < needle.size(); j++) {
          if (haystack[i] == needle[j]) {
            i++;
          } else {
            found = false;
            i -= j;
            break;
          }
        }
        if (found) {
          return i - needle.size();
        }
      }
      return -1;
    }
};
