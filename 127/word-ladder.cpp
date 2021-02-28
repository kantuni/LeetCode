class Solution {
  public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      set<string> words(wordList.begin(), wordList.end());
      map<string, int> color, dist;
      queue<string> q;
      q.push(beginWord);
      color[beginWord] = 1;
      while (!q.empty()) {
        string cur = q.front(); q.pop();
        if (cur == endWord) {
          return dist[cur] + 1;
        }
        for (int i = 0; i < cur.size(); i++) {
          for (int j = 0; j < 26; j++) {
            string nxt = cur;
            nxt[i] = 'a' + j;
            if (words.count(nxt) > 0 and color.count(nxt) == 0) {
              q.push(nxt);
              color[nxt] = 1;
              dist[nxt] = dist[cur] + 1;
            }
          }
        }
      }
      return 0;
    }
};
