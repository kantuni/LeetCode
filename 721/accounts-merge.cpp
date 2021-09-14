class Solution {
  private:
    vector<int> parent;
  
    int find(int x) {
      while (x != parent[x]) {
        x = parent[x];
      }
      return x;
    }
  
    bool same(int x, int y) {
      return find(x) == find(y);
    }
  
    void merge(int x, int y) {
      int px = find(x);
      int py = find(y);
      if (rand() % 2 == 0) {
        parent[px] = py;
      } else {
        parent[py] = px;
      }
    }

  public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      parent.resize(accounts.size());
      iota(parent.begin(), parent.end(), 0);
      map<string, int> emailToAccountIndex;
      for (int i = 0; i < accounts.size(); i++) {
        for (int j = 1; j < accounts[i].size(); j++) {
          string email = accounts[i][j];
          if (emailToAccountIndex.count(email) == 0) {
            emailToAccountIndex[email] = i;
          } else {
            merge(emailToAccountIndex[email], i);
          }
        }
      }
      map<int, set<string>> accountIndexToEmails;
      for (auto [email, accountIndex]: emailToAccountIndex) {
        accountIndexToEmails[find(accountIndex)].insert(email);
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
