class Solution {
  private:
    string removeLeadingZeros(string num) {
      if (num.size() == 0) {
        return "0";
      }
      auto firstNonZero = num.find_first_not_of("0");
      if (firstNonZero == string::npos) {
        return "0";
      }
      return num.substr(firstNonZero);
    }

  public:
    string removeKdigits(string num, int k) {
      if (num.size() == k) {
        return "0";
      }
      while (k--) {
        bool removed = false;
        for (int i = 0; !removed and i < num.size() - 1; i++) {
          if (num[i] > num[i + 1]) {
            num.erase(i, 1);
            removed = true;
          }
        }
        for (int i = 0; !removed and i < num.size() - 1; i++) {
          if (num[i] < num[i + 1]) {
            num.erase(i + 1, 1);
            removed = true;
          }
        }
        if (removed) {
          continue;
        }
        if (num.size() < 2) {
          return "0";
        }
        num.erase(1, 1);
      }
      return removeLeadingZeros(num);
    }
};
