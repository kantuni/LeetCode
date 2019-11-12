class Solution {
  private:
    vector<bool> sieve(int n) {
      vector<bool> isPrime(n + 1, true);
      isPrime[0] = isPrime[1] = false;
      for (int i = 2; i * i <= n; i++) {
        for (int j = 0; i * i + i * j <= n; j++) {
          isPrime[i * i + i * j] = false;
        }
      }
      return isPrime;
    }

  public:
    int countPrimes(int n) {
      vector<bool> isPrime = sieve(n);
      int ans = 0;
      for (int i = 2; i < n; i++) {
        ans += isPrime[i];
      }
      return ans;
    }
};
