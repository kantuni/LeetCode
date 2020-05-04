class Solution {
  public:
    string getHint(string secret, string guess) {
      map<char, int> sm;
      for (int i = 0; i < secret.size(); i++) {
        sm[secret[i]]++;
      }
      map<char, int> gm;
      for (int i = 0; i < guess.size(); i++) {
        gm[guess[i]]++;
      }
      int bulls = 0;
      for (int i = 0; i < guess.size(); i++) {
        bulls += i < secret.size() and guess[i] == secret[i];
      }
      int cows = 0;
      for (auto [c, cnt]: gm) {
        cows += min(sm[c], cnt);
      }
      return to_string(bulls) + "A" + to_string(cows - bulls) + "B";
    }
};
