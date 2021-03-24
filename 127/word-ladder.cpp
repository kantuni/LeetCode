class Solution {
  public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      set<string> words(wordList.begin(), wordList.end());
      queue<pair<string, int>> q;
      map<string, int> color, dist;
      q.push({beginWord, 1});
      color[beginWord] = 1;
      while (!q.empty()) {
        auto [w, d] = q.front(); q.pop();
        if (w == endWord) {
          return d;
        }
        for (int i = 0; i < w.size(); i++) {
          for (int j = 0; j < 26; j++) {
            string nxt = w;
            nxt[i] = 'a' + j;
            if (words.count(nxt) > 0 and color.count(nxt) == 0) {
              q.push({nxt, d + 1});
              color[nxt] = 1;
            }
          }
        }
      }
      return 0;
    }
};
