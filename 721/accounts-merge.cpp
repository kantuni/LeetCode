struct UnionFind {
  vector<int> parent;

  UnionFind(int n) {
    parent.assign(n, 0);
    iota(parent.begin(), parent.end(), 0);
  }
  
  int find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]);
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (rand() % 2 == 0) {
      parent[x] = y;
    } else {
      parent[y] = x;
    }
  }
};

class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      UnionFind memo(accounts.size());
      map<string, int> emailToAccountIndex;
      for (int i = 0; i < accounts.size(); i++) {
        for (int j = 1; j < accounts[i].size(); j++) {
          string email = accounts[i][j];
          if (emailToAccountIndex.count(email) == 0) {
            emailToAccountIndex[email] = i;
          } else {
            memo.merge(emailToAccountIndex[email], i);
          }
        }
      }
      map<int, set<string>> accountIndexToEmails;
      for (auto [email, accountIndex]: emailToAccountIndex) {
        accountIndexToEmails[memo.find(accountIndex)].insert(email);
      }
      vector<vector<string>> ans;
      for (auto [accountIndex, emails]: accountIndexToEmails) {
        string name = accounts[accountIndex][0];
        vector<string> entry = {name};
        entry.insert(entry.end(), emails.begin(), emails.end());
        ans.push_back(entry);
      }
      return ans;
    }
};
