class Solution {
  public:
    string getHint(string secret, string guess) {
      vector<int> sm(10);
      for (int i = 0; i < secret.size(); i++) {
        sm[secret[i] - '0']++;
      }
      vector<int> gm(10);
      for (int i = 0; i < guess.size(); i++) {
        gm[guess[i] - '0']++;
      }
      int matches = 0;
      for (int i = 0; i < 10; i++) {
        matches += min(sm[i], gm[i]);
      }
      int bulls = 0;
      for (int i = 0; i < guess.size(); i++) {
        bulls += i < secret.size() and guess[i] == secret[i];
      }
      return to_string(bulls) + "A" + to_string(matches - bulls) + "B";
    }
};
