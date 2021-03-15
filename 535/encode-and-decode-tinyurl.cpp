class Solution {
  private:
    string sigma = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    map<string, string> memo;

  public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
      int id = memo.size() + 1;
      string shortUrl;
      while (id > 0) {
        shortUrl += sigma[id % 62];
        id /= 62;
      }
      memo[shortUrl] = longUrl;
      return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
      return memo[shortUrl];
    }
};
